#include <iostream>
#include <vector>

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        // sort array
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        int p1 = 0;
        int p2 = nums.size()-1;
        while(p1 <= p2){
            result.push_back(nums[p1]);
            if(p1!=p2)
                result.push_back(nums[p2]);
            p1++;
            p2--;
        }
        nums = result;
    }
};

int main(){
    Solution mySolution;
    std::vector<int> testNums = {3, 5, 2, 1, 6, 4};
    mySolution.wiggleSort(testNums);
    for(auto& el: testNums){
        std::cout<<el<<std::endl;
    }
}