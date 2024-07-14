#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        // sliding window
        // initliaze two pointers
        int p1(0), p2(0);
        // initalize max window width
        int maxsize = INT32_MIN;
        vector<int> elems = {0, 0};
        while(p2 < nums.size()){
            // we can only move up the second pointer if we dont have more than one 0 element or the current elem is a 1
            // i.e. elems[0] < 1
            if(nums[p2]==1 || elems[0] < 1){
                elems[nums[p2]]++;
                p2++;
            } else { // we already have a zero element so we must move up first pointer until its no longer the case
                elems[nums[p1]]--;
                p1++;
            }
            maxsize = max(maxsize, p2-p1);
        }
        return maxsize;
    }
};