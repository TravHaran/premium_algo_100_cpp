#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool canPermutePalindrome(string s){
            unordered_map<char, int> palindrome_map;
            for(auto& el : s){
                if (palindrome_map.count(el)) {
                    (palindrome_map[el]==1) ? palindrome_map.erase(el) : palindrome_map[el]--;
                } else {
                    palindrome_map[el]++;
                }
            }
            return palindrome_map.size() <= 1;
        }
};