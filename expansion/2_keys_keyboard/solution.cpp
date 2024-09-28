class Solution {
private: 
    int N;
    vector<vector<int>> cache;
    int dfs(int count, int clipboard){
        if(count==N) return 1;
        if(count > N) return 1001;
        if(cache[count][clipboard]!=-1) return cache[count][clipboard];
        //paste
        int res1 = 1 + dfs(count + clipboard, clipboard);
        //copy&paste
        int res2 = 2 + dfs(count + count, count);
        return cache[count][clipboard] = min(res1, res2);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        cache = vector<vector<int>>(n+1, vector<int>(n/2 + 1, -1));
        N = n;
        return dfs(1, 1);
    }
};