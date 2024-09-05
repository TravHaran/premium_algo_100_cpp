class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        int sum = 0;
        int dup = INT_MIN;
        vector<bool> seen(size-1, false);
        // identify duplicate & compute total sum
        for(int i = 0; i < size; i++){
            sum += nums[i];
            if(dup==INT_MIN){
                if(seen[nums[i]-1]) dup = nums[i];
                seen[nums[i]-1] = true;
            }
        }
        // compute correct sum
        int correct_sum = (size*(size+1))>>1;
        if(sum > correct_sum){
            // error resulted in an increase
            // missing value is duplicate value - difference
            return {dup, dup - (sum - correct_sum)};
        }
        // otherwise error resulted in a decrease
        // missing value is duplicate value + difference
        return {dup, dup + (correct_sum - sum)};
    }
};