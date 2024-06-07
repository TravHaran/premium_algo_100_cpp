#include <iostream>
#include <vector>

class Solution {
    public:
        void reverseWords(std::vector<char>& s) {
            // reverse entire string
            std::reverse(s.begin(), s.end());
            // start points to beginning of current word
            // 'end' points to position just after current word
            int start = 0, end = 0;
            int n = s.size();
            while(start < n){
                // move right to the position just after the current word
                while(end < n && s[end] != ' ') end++;
                // Note: in C++ reverse operates on [start, end) so rightmost is not included
                std::reverse(s.begin() + start, s.begin() + end);
                // move start and end to beginning of next word
                end++;
                start = end;
            } 
        }
};

int main(){
    Solution mySolution;
    std::vector<char> testS = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    mySolution.reverseWords(testS);
    std::vector<char> expected = {'b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e'};
    assert(testS == expected);
    return 0;
}