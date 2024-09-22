class Solution {
private:
   void findFactorPairs(vector<int>& sol, int lower){
        int n = sol.back();
        int size = sol.size();
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                int minFactor = min(i, n/i);
                if(minFactor >= lower){
                    sol[size-1] = minFactor;
                    sol.push_back(max(i, n/i));
                    res.push_back(sol);
                    findFactorPairs(sol, minFactor);
                    sol.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) {
        vector<int> sol = {n};
        findFactorPairs(sol, 0);
        return res;
    }
};