#include <iostream>
#include <vector>
#include <tuple>
#include <string>


class Solution {
    public:
        int maxDistance(std::vector<std::vector<int>>& arrays) {
            // define an array of min values
                // each entry in the array stores the min value of the input array mapped to it's index
            // iterate through all arrays to set the min value found, at the array index it was found at
            // iterate through all arrays again to 
            std::vector<std::tuple<int, int>> minmax_arr;
            int min;
            int max;
            for(auto& arr : arrays){
                // arrays are sorted in ascending order
                min = arr.front();
                max = arr.back();
                minmax_arr.push_back({min, max});
            }
            int cur_min;
            int cur_max;
            int output = INT32_MIN;
            for(int i = 0; i < minmax_arr.size(); i++){
                cur_min = std::get<0>(minmax_arr[i]);
                // std::cout<<"min: "<<cur_min<<std::endl;
                for(int j = 0; j < minmax_arr.size(); j++){
                    if(j != i){
                        cur_max = std::get<1>(minmax_arr[j]);
                        // std::cout<<"max: "<<cur_max<<std::endl;
                        output = std::max(output, cur_max - cur_min);
                        // std::cout<<"output: "<<output<<std::endl;
                    }
                }
            }
            return (output == INT32_MIN) ? 0 : output;
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

