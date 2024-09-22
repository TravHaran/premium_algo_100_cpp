class Solution {
    // TOP DOWN 1D DP
private:
    int N;
    vector<int> cache;
    int dfs(int n){
        if(n <= 0) return 0;
        if(cache[n]!=-1) return cache[n];
        int ans = 0;
        ans = max(ans, dfs(n-1)+1);
        for(int i = 3; i <=6; i++){
            ans = max(ans, dfs(n-i)*(i-1));
        }
        return cache[n] = ans;
    }

public:
    int maxA(int n) {
        N = n;
        cache = vector<int>(n+1, -1);
        return dfs(n);
    }
};
