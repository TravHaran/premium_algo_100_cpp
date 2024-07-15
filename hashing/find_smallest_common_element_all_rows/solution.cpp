#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> freq;
        for(auto& row : mat){
            for(auto& el: row){
                freq[el]++;
            }
        }
        for(auto& n : mat[0]){
            if(freq[n] == mat.size()) return n;
        }
        return -1;
    }
};