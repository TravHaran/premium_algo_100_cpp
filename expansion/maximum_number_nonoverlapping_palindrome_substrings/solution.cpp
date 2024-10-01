class Solution {
private:
    // This function prepares the string by inserting '#' between characters
    // This step ensures that both odd- and even-length palindromes can be treated the same way.
    string prepare_string(string& s) {
        string t;
        for(auto& el : s) 
            t += (string)"#" + el; // Inserting '#' between each character
        return t + "#"; // Add an ending '#'
    }

    // Modified Manacher's algorithm to solve the problem
    int manacher(string s, int k) {
        int n = s.size();
        s = "$" + s + "^"; // Adding boundary characters to avoid bounds checking
        // l and r track the borders of the current palindrome
        int l = 1, r = 1;
        vector<int> d(n+2); // Palindrome radius array, size n+2 for boundary characters
        // 'ans' for result, 'far' to track the last included palindrome's end index
        int ans = 0, far = -1; 
        // Compute palindromes centered at each position
        for (int i = 1; i <= n; i++) {
            // Calculate the mirror index relative to the current center 'i'
            int j = l + (r - i);
            // If 'i' is within the current known palindrome, set the initial radius using the mirror
            d[i] = max(0, min(r - i, d[j]));
            // Expand the palindrome centered at 'i' as long as the characters match
            while (s[i - d[i]] == s[i + d[i]]) 
                d[i]++;
            // Update the left and right boundaries if the palindrome centered at 'i' expands beyond 'r'
            if (i + d[i] > r) {
                r = i + d[i];
                l = i - d[i];
            }
            // We only care about palindromes of length >= k
            // since 'd[i]' counts the length including both directions with centre, length: d[i]-1
            if (d[i] - 1 >= k) {
                // Ensure correct length handling: 
                    // if k and palindrome length have different parities then we know there is a mismatch 
                    // the smallest substring we can choose is k+1, if the have the same parity choose k
                int len = k; 
                if((d[i]-1) % 2 != k%2) len++;
                int left = (i - len)/2; // Convert from the modified string index to the original string index
                int right = left + len - 1;
                // Ensure the current palindrome doesn't overlap with the previous one
                if (far < left) {
                    ++ans; // Increment the count of non-overlapping palindromes
                    far = right; 
                }
            }
        }
        // Return the total count of non-overlapping palindromes
        return ans; 
    }

public:
    int maxPalindromes(string s, int k) {
        // prepare string for manacher algo
        s = prepare_string(s);
        return manacher(s, k);
    }
};