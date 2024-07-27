#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int lower = toBeRemoved[0];
        int upper = toBeRemoved[1];
        vector<vector<int>> output;
        for(auto& el : intervals){
            if(el[1] <= lower || el[0] >= upper){
                // NO OVERLAP
                output.push_back(el);
            } else {
                // OVERLAP
                if(el[0] < lower){
                    output.push_back({el[0], lower});
                }
                if(el[1] > upper){
                    output.push_back({upper, el[1]});
                }
            }
        }
        return output;
    }
};

