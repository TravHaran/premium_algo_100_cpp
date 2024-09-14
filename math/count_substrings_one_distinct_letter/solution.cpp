class Solution {
public:
    int countLetters(string s) {
        int width = 0;
        int l = 0, r = 1;
        int count = 0;
        while(r < s.size()){
            if(s[r]==s[r-1]){
                r++;
            } else {
                width = r-l;
                count += (width*(width+1))>>1;
                l = r;
                r++;
            }
        }
        if(l!=r){
            width = r-l;
            count += (width*(width+1))>>1;
        }
        return count;
    }
};