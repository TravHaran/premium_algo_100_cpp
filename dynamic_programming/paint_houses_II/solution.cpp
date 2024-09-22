class Solution {
private:
    int k;
    int _find(vector<vector<int>>& costs){
        vector<int> dp = {costs[0]};
        int n = costs.size();
        for(int i = 1; i < n; i++){
            vector<int> currCosts(k);
            for(int j = 0; j < k; j++) {
                currCosts[j] = costs[i][j] + getMin(dp, j);
            }
            dp = currCosts;
        }
        int minimum = INT_MAX;
        for(auto& el : dp){
            minimum = min(minimum, el);
        }
        return minimum;
    }
    
    int getMin(vector<int>& colors, int exclude){
        int minVal = INT_MAX;
        int count = 0;
        for(int i = 0; i < colors.size(); i++){
            if(i!=exclude){
                minVal = min(minVal, colors[i]);
                count++;
            }
        }
        return minVal;
    }
public:
    int minCostII(vector<vector<int>>& costs) {
        k = costs[0].size();
        return _find(costs);
    }
};