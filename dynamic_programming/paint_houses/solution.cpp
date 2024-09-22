class Solution {
private:
    int _find(vector<vector<int>>& costs){
        int a = costs[0][0], b = costs[0][1], c = costs[0][2];
        int n = costs.size();
        for(int i = 1; i < n; i++){
            int xa = costs[i][0] + min(b, c);
            int xb = costs[i][1] + min(a, c);
            int xc = costs[i][2] + min(a, b);
            a = xa, b= xb, c = xc;
        }
        return min({a, b, c});
    }
public:
    int minCost(vector<vector<int>>& costs) {
        return _find(costs);
    }
};