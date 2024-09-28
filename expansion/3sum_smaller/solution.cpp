class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int tripletSum = nums[i] + nums[j] + nums[k];
                if(tripletSum < target){
                    // all pairs (j, j + 1) ... (j, k - 1) will also be less than target,
                    // so add their count to counter and lo is done now, so increase lo
                    res += (k-j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};