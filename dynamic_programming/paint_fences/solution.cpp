class Solution {
    // Top Down DP
private:
    int _numWays(int n, int k){
        if(n == 1) return k;
        else if (n == 2) return k*k;
        return (_numWays(n-1, k) + _numWays(n-2, k))*(k-1);
    }

public:
    int numWays(int n, int k) {
        return _numWays(n, k);
    }
};