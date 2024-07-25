#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {                    
                // too long
                if(j >= words.size()) return false; 
                // too short
                else if(i > words[j].size()) return false;
                // letter not equal
                else if(words[i][j]!=words[j][i]) return false;
            }
        }
        return true;
    }
};