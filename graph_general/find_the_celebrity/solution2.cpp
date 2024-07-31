/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celeb = 0;
        for(int i = 0; i < n; i++){
            if(knows(celeb, i)) celeb = i;
        }
        if(knowNobody(celeb, n)) return celeb;
        return -1;  
    }

    bool knowNobody(int x, int n){
        for(int i = 0; i < n; i++){
            if((!knows(i, x) || knows(x, i)) && i != x) return false;
        }
        return true;
    }

};