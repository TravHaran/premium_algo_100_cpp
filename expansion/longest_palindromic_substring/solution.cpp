class Solution {
public:
    // Time: O(n^2), Space: O(n)
    string longestPalindrome(string s){
        int length = 0;
        string res;
        for(int i = 0; i < s.size(); i++){
            // odd length palindromes
            int l = i, r = i;
            while(l >=0 && r < s.size() && s[l]==s[r]){
                if(r-l +1 > length){
                    length = r-l +1;
                    res = s.substr(l,r-l +1);
                }
                l--;
                r++;
            }
            // even length palindromes
            l = i, r = i+1;
            while(l >=0 && r < s.size() && s[l]==s[r]){
                if(r-l +1 > length){
                    length = r-l +1;
                    res = s.substr(l,r-l +1);
                }
                l--;
                r++;
            }
        }
        return res;
    }

};