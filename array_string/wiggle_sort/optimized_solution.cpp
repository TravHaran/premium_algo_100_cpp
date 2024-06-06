#include <iostream>
#include <vector>

class Solution {
    public:
        void wiggleSort(std::vector<int>& nums) {
            if(nums.size() < 1) return;
            // O(n) approach
            int pol = -1;
            int dif;
            for(int i = 0; i < nums.size() - 1; i++){
                // compute dif
                dif = nums[i] - nums[i+1];
                if((dif < 0 && pol > 0) || (dif > 0 && pol < 0)){
                    // swap
                    int temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
                // switch polarity
                pol *= -1;
            }
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