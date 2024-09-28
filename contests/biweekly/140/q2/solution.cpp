class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        // sort heights
        sort(maximumHeight.begin(), maximumHeight.end());
        long result = 0;
        int n = maximumHeight.size();
        int prev;
        // start from largest to smallest & assign max possibel height
        for(int i = n-1; i >= 0; i--){
            int val = maximumHeight[i];
            if(i < n-1) {
                if(val >= prev){
                    val = prev-1;
                }
            }
            if(val <= 0) return -1;
            result += val;
            prev = val;
        }
        return result;
    }
};