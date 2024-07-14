#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() < 2) return s.size();
        int p1 = 0;
        int p2 = 0;
        int maxsize = INT32_MIN;
        int curr_size;
        unordered_map<char, int> unique;
        while(p2 < s.size()){
            if(unique.count(s[p2]) || unique.size()<2){
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