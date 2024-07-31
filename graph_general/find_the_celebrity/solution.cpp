/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for(int i = 0; i < n; i++){
            if(everyoneKnowsMe(i, n) && knowNobody(i, n)) return i;
        }
        return -1;
        
    }

    bool everyoneKnowsMe(int x, int n){
        for(int i = 0; i < n; i++){
            if(i != x && !knows(i, x)) return false;
        }
        return true;
    }

    bool knowNobody(int x, int n){
        for(int i = 0; i < n; i++){
            if(i != x && knows(x, i)) return false;
        }
        return true;
    }

};