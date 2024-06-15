#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // identify shorter string
        string* shorter;
        string* longer;
        (word1.size() <= word2.size()) ? shorter = &word1 : shorter = &word2;
        (*shorter == word1) ? longer = &word2 : longer = &word1;
        // set shorter count
        int short_count = shorter->size();
        // alternatively merge
        string merged;
        int idx = 0;
        while(short_count != 0){
            merged.push_back(word1[idx]);
            merged.push_back(word2[idx]);
            idx++;
            short_count--;
        }
        // merge remainder
        merged += longer->substr(idx);
        return merged;
    }
};