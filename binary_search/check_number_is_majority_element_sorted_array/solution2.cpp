class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int lim = nums.size()/2;
        int first_idx = 0;
        //binary search to find first occurence (lower bound)
        int l = 0, r = nums.size()-1, mid;
        while(l <= r){
            mid = r-l/2;
            if(nums[mid]>=target){
                r = mid-1;
                first_idx = mid;
            } else {
                l = mid + 1;
            }
        }
        // check if the element at index firstIndex + num.length / 2 is equal to target or not
        if((first_idx + lim) < nums.size() && nums[first_idx + lim]==target) return true;
        return false;
    }
};