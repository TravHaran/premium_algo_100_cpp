class Solution {
private:
    vector<vector<int>> cache;
    int _find(vector<vector<int>>& costs, int house, int col){
        int minAmount = INT_MAX;
        if(house == 0){
            for(int i = 0; i < costs[house].size(); i++){
                if(i != col) minAmount = min(minAmount, costs[house][i]);
            }
            return minAmount;
        }
        if(cache[house][col]!=-1) return cache[house][col];
        for(int i = 0; i < costs[house].size(); i++){
            if(i != col){
                minAmount = min(minAmount, costs[house][i] + _find(costs, house-1, i));
            }
        }
        cache[house][col] = minAmount;
        return minAmount;
    }
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        cache = vector<vector<int>>(n, vector<int>(k+1, -1));
        return _find(costs, n-1, k);
    }
};