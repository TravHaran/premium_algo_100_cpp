#include <vector>

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int N = picture.size();
        int M = picture[0].size();
        // define two arrays, one for the number of rows, and one for the number of cols
        vector<int> rowCount(N, 0);
        vector<int> colCount(M, 0);
        //iterate through matrix and every time we encounter a B we increment the count at it's respective position in rowCount and colCount
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(picture[i][j]=='B'){
                    rowCount[i]++;
                    colCount[j]++;
                }

            }
        }
        // to check for a lonely pixel we need to iterate through the matrix again, this time when we encounter B
        // we simply check if its respective rowCount and colCount is 1
        int count(0);
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < M; j++){
                if(picture[i][j]=='B'){
                    if(rowCount[i]==1 && colCount[j]==1) count++;
                }
            }
        }
        return count;
    }
};