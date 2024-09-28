class Solution {
    // list all perfect square numbers
        // iterate from 1 to sqrt(n)
            // insert i*i to list
    // now it's just like the unbounded knapsack where the capacity is n
    // and the cost is the perfect square numbers
private: 
    int dfs(int n, int i, vector<int>& perfects, vector<vector<int>>& cache){
        // base case: i == perfects.size() or sum == n
        if(n==0) return 0;
        if(i == perfects.size()) return INT_MAX;
        if(cache[i][n]!=-1) return cache[i][n];
        // skip 
        cache[i][n] = dfs(n, i+1, perfects, cache);
        // include
        int newSum = n - perfects[i];
        if(n >= perfects[i]){
            int count = dfs(newSum, i, perfects, cache);
            if(count!=INT_MAX) cache[i][n] = min(cache[i][n], 1 + count);
        }
        return cache[i][n];
    }

public:
    int numSquares(int n) {
        // list all perfect squares
        vector<int> perfects;
        for(int i = 1; i*i <= n; i++){
            perfects.push_back(i*i);
        }
        // now we can apply unbounded knapsack dp pattern
        vector<vector<int>> cache(perfects.size(), vector<int>(n+1, -1));
        return dfs(n, 0, perfects, cache);
    }
};