class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int lim = nums.size()/2;
        int count = 0;
        for(auto& el : nums){
            if(el==target) count++;
        }
        return count > lim;
    }
};