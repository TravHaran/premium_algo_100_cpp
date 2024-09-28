class Solution {
public:
    // three pointer approach
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int j, k, res, dif = INT_MAX, n = nums.size();
        for(int i = 0; i < n-1; i++){
            j = i+1, k = n-1;
            while(j < k){
                int tripletSum = nums[i] + nums[j] + nums[k];
                int curDif = abs(target - tripletSum);
                if(curDif < dif){
                    dif = curDif;
                    res = tripletSum;
                }
                if(tripletSum < target) j++;
                else if(tripletSum > target) k--;
                else return tripletSum;
            }
        }
        return res;
    }
};