#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num2_map;
        vector<int> mappings;
        for(int i = 0; i < nums2.size(); i++){
            num2_map[nums2[i]] = i;
        }
        for(int& num: nums1){
            mappings.push_back(num2_map[num]);
        }
        return mappings;
    }
};