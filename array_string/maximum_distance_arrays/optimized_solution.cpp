#include <iostream>
#include <vector>
#include <tuple>
#include <string>


class Solution {
    public:
        int maxDistance(std::vector<std::vector<int>>& arrays) {
            int output = INT32_MIN;
            int cur_max = -1e4, cur_min = 1e4;
            int cur_output;
            for(auto& arr: arrays){
                cur_output = std::max(arr.back() - cur_min, cur_max - arr.front());
                output = std::max(output, cur_output);
                cur_max = std::max(cur_max, arr.back());
                cur_min = std::min(cur_min, arr.front());
            }
            return output;
        }
};

int main(){
    Solution mySolution;
    std::vector<std::vector<int>> testArr = {{1,2,3},{4,5},{1,2,3}};
    int testOutput = mySolution.maxDistance(testArr);
    std::cout<<testOutput<<std::endl;
    std::vector<std::vector<int>> testArr2 = {{1},{1}};
    int testOutput2 = mySolution.maxDistance(testArr2);
    std::cout<<testOutput2<<std::endl;
    return 0;
}
