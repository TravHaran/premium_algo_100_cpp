#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        // map similar pairs of words
        unordered_map<string, unordered_set<string>> pair_map;
        for(auto& pair: similarPairs){
            pair_map[pair[0]].insert(pair[1]);
            pair_map[pair[1]].insert(pair[0]);
        }
        for(int i = 0; i < sentence1.size(); i++){
            if(sentence1[i] != sentence2[i]){
                if(!pair_map[sentence1[i]].count(sentence2[i])) return false;
            }
        }
        return true;
    }
};

