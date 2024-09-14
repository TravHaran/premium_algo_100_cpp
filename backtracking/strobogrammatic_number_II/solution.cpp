// Time: O(N*5^[N/2])
// Space: O(N*5^[N/2])
class Solution {
    // strobogrammatic digits
    // 0 -> 0
    // 1 -> 1
    // 6 -> 9
    // 8 -> 8
    // 9 -> 6
    // of these digits we know that 0, 1, 8 have identical transformations
private:
    void _find(string& num, int l, int r){
        if(l < r){
            for(auto& [key, val] : strob){
                if(key=='0' && l==0) continue;
                num[l] = key;
                num[r] = val;
                _find(num, l+1, r-1);
            }
        } else if(l == r){
            for(auto& val : identical){
                num[l] = val;
                _find(num, l+1, r-1);
            }
        } else { // l > r
            res.push_back(num);
        }
    }

public:
    vector<string> res;
    vector<pair<char, char>> strob = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    vector<char> identical = {'0', '1', '8'};
    vector<string> findStrobogrammatic(int n) {
        string num(n, '.'); // initialize empty string of size n
        _find(num, 0, n-1); // recursive backtrack
        return res;
    }
};