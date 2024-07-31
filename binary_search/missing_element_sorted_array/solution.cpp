class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] - nums[0] - mid >= k) {
                right = mid-1;
            } else{
                left = mid + 1;
            }
        }
        return nums[0] + k + left-1;
    }
};