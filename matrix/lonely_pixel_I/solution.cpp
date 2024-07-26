#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        // iterate through matrix
        // have a set where we store the rows where we encounter pixel
        // have a set where we store the columns where we encounter the pixel

        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> colMap;
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j]=='B'){
                    rowMap[i].insert(j);
                    colMap[j].insert(i);
                }
            }
        }
        int count{0};
        for(auto& [key, val] : rowMap){
            if(val.size()==1 && colMap[key].size()==1) count++;
        }
        return count;
    }
};