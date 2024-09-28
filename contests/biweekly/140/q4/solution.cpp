// This solution results in TLE
class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        if (n < m) return -1;  // Impossible case: pattern is longer than s

        for (int i = 0; i <= n - m; ++i) {
            int mismatch_count = 0;

            // Check the substring s[i:i+m] against pattern
            for (int j = 0; j < m; ++j) {
                if (s[i + j] != pattern[j]) {
                    mismatch_count++;
                }
                // Early exit if we exceed one mismatch
                if (mismatch_count > 1) {
                    break;  
                }
            }

            // If the substring has at most one mismatch, return the starting index i
            if (mismatch_count <= 1) {
                return i;
            }
        }

        // If no valid substring is found, return -1
        return -1;
    }
};