#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size()<k) return s.size();
        if(k==0) return k;
        unordered_map<char, int> unique;
        int p1(0), p2(0), maxsize = INT32_MIN;
        while(p2 < s.size()){
            if(unique.count(s[p2]) || unique.size() < k){
                unique[s[p2]]++;
                p2++;
            } else {
                (unique[s[p1]]==1) ? unique.erase(s[p1]) : unique[s[p1]]--;
                p1++;
            }
            maxsize = max(maxsize, p2-p1);
        }
        return maxsize;
    }
};