class Solution {
    // Decision Tree
    // 2D TOP DOWN DP
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
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        cache = vector<vector<int>>(costs.size(), vector<int>(costs[0].size()+1, -1));
        return _find(costs, n-1, 3);
    }
};