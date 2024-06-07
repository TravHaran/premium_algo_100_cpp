#include <iostream>
#include <vector>

class Solution {
public:
    std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
        int length = s.length();
        // compute resulting shift
        int shifts = 0;
        for(auto& el: shift){
            int dir = el[0];
            int dist = el[1];
            (dir==0) ? shifts += dist : shifts -= dist;
        }
        shifts %= length;
        int start = (shifts < 0) ? length + shifts : shifts;
        std::string result = s.substr(start) + s.substr(0, start);
        return result;
    }
};


int main(){
    Solution mySolution;
    // std::string testString = "abcdefg";
    std::string testString = "wpdhhcj";
    // std::vector<std::vector<int>> testShift = {{1,1},{1,1},{0,2},{1,3}};
    std::vector<std::vector<int>> testShift = {{0,4}};
    std::string testResult = mySolution.stringShift(testString, testShift);
    std::cout<<testResult<<std::endl;
    return 0;
}