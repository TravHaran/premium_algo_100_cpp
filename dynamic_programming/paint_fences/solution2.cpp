class Solution {
    // Bottom Up DP
private:
    int _numWays(int n, int k){
        if(n == 1) return k;
        else if (n == 2) return k*k;
        int val1 = k, val2 = k*k, i = 2;
        while(i < n){
            int tmp = val2;
            val2 = (val1 + val2) * (k-1);
            val1 = tmp;
            i++;
        }
        return val2;
    }

public:
    int numWays(int n, int k) {
        return _numWays(n, k);
    }
};