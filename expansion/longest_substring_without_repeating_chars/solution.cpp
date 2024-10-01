#include <array>
#include <string>
using namespace std;

class Solution {
public:
    // Optimized sliding window approach
    // Time: O(n), Space: O(1)
    int lengthOfLongestSubstring(string s) {
        // we know the max string size is 50,000
        // we can use an unsigned short to represent index values
        // unsigned short = 16 bits = 2^16 = ~65,000
        unsigned short n = s.size();
        if (n <= 1) return n;
        // since a array size is fixed we use a static array
        // this provides faster access since it's stack allocated
        // whereas dynamic array is heap allocated
        array<unsigned short, 128> table;
        // intialize array values to n since we know index values will be less than n
        table.fill(n);
        unsigned short l = 0, maxLen = 0;
        for(auto r = 0; r < n; r++){
            if(table[s[r]]!=n && table[s[r]] > l){ // if duplicate found
                // move window to furthest position without duplicate
                l = table[s[r]];
            }
            // now theres no more duplicates so we update table and calculate max size
            // we set it to r+1 so that after moving l
            // the character at s[r] will not be included in the substring again
            table[s[r]] = r+1;
            maxLen = max(maxLen, (unsigned short)(r - l + 1));
        }
        return maxLen;  
    }
};