#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_set<int> unique;
        vector<int> duplicate;
        for(auto& el : nums) {
            if(!unique.count(el)){
                unique.insert(el);
            } else {
                duplicate.push_back(el);
            }
        }
        for(auto& d : duplicate){
            unique.erase(d);
        }
        int result = -1;
        for(auto& n : unique){
            result = max(result, n);
        }
        return result;
    }
};