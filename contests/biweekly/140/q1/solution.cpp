class Solution {
private:
    int digitSum(int n){
        int sum  = 0;
        while(n!= 0){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int minEl = INT_MAX;
        for(auto& n : nums){
            minEl = min(minEl, digitSum(n));

        }
        return minEl;
        
    }
};