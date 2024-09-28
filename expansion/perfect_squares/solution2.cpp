class Solution {
    // list all perfect square numbers
        // iterate from 1 to sqrt(n)
            // insert i*i to list
    // now it's just like the unbounded knapsack where the capacity is n
    // and the cost is the perfect square numbers
public:
    int numSquares(int n) {
        // Step 1: Generate all perfect squares <= n
        vector<int> perfects;
        for (int i = 1; i * i <= n; ++i) {
            perfects.push_back(i * i);
        }
        // Step 2: Initialize a dp array where dp[j] is the minimum number of squares to sum up to j
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // Base case: 0 squares are needed to make 0

        // Step 3: Fill the dp array
        // For each perfect square, we iterate through possible capacities 
        // from the current square value up to n
        for(int i = 0; i < perfects.size(); i++){
            for(int c = perfects[i]; c <=n; c++){
                int count = dp[c - perfects[i]];
                if(count != INT_MAX) dp[c] = min(dp[c], 1 + count);
            }
        }
        return dp[n];
    }
};