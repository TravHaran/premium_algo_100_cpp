class Solution {
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // 0 flipped is 0
    // 6 flipped is 9
    // 8 flipped is 8
    // 9 flipped is 6
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> strob = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        int l = 0, r = num.size()-1;
        while(l <= r){
            if(!strob.count(num[l]) || !strob.count(num[r])) return false;
            else if(num[l] != strob[num[r]]) return false;
            l++;
            r--;
        }
        return true;
    }
};