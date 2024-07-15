#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> idx_map;
        for(int i = 0; i < keyboard.size(); i++){
            idx_map[keyboard[i]] = i;
        }
        int time(0);
        int prev_idx = 0;
        for(auto& el: word){
            time += abs(prev_idx - idx_map[el]);
            prev_idx = idx_map[el];
        }
        return time;
    }
};