#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // for an mxk mat x kxn mat, the output mat is of size: mxn
        // initialize the output vector
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        vector<vector<int>> output(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < k; j++){
                if(mat1[i][j]!=0) {
                    for(int a = 0; a < n; a++){
                        output[i][a] += mat1[i][j] * mat2[j][a];
                    }
                }
            }
        }
        return output;
    }
};