// Fails test case 2
/**
this code fails test case 2 where 
word1 = "bacdc"
word2 = "abc"
and the expected output is [1, 2, 4]
but the program outputs []
Explanation: the lexicographically smallest valid sequence of indices is [1,2,4]
word1[1] is already 'a'
change word1[2] to 'b'
word1[4] is already 'c'
 */

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n < m) return {};  // Impossible case: word1 is smaller than word2

        vector<int> result;
        int i = 0;  // Pointer for word1
        bool mismatch_used = false;  // Track if a mismatch has been used

        // Iterate over each character of word2
        for (int j = 0; j < m; ++j) {
            bool found = false;  // Track if a match or mismatch is found for word2[j]
            
            // Try to find the next matching or nearly matching character in word1
            while (i < n) {
                if (word1[i] == word2[j]) {
                    // Exact match: add index and move to next character
                    result.push_back(i);
                    i++;
                    found = true;
                    break;
                } else if (!mismatch_used) {
                    // First mismatch: take this index and mark the mismatch used
                    result.push_back(i);
                    i++;
                    mismatch_used = true;
                    found = true;
                    break;
                }
                i++;  // Move to the next character in word1
            }

            // If no valid match or mismatch found, return empty array
            if (!found) {
                return {};
            }
        }

        return result;
    }
};