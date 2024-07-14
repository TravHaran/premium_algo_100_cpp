#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        // use sliding window
        // initialize 2 pointers
        int p1(0), p2(0);
        // we want no repeated characters so use a set
        unordered_set<char> unique;
        // keep track of number of susbtrings found
        int count(0);
        while(p2 < s.size()){
            while(unique.count(s[p2])){
                unique.erase(s[p1]);
                p1++;
            }
            unique.insert(s[p2]);
            if(unique.size()==k){
                count++;
                unique.erase(s[p1]);
                p1++;
            } 
            p2++;
        }
        return count; 
    }
};