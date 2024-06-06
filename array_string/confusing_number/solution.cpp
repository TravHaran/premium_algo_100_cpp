#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool confusingNumber(int n) {
        // define a rotation map for valid integers
        std::unordered_map<int, int> rotation_map = {
            {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}
        };
        // get digit length of n
        int length = 1;
        int value = n;
        while(value /= 10){
            length++;
        }
        value = n;
        int reversed = 0;
        int place_val = std::pow(10, length-1);
        // for every digit in n verify that it is valid
        for(int i = 0; i < length; i++){
            // get digit
            int dig = value % 10;
            value = value/10;
            if (!rotation_map.count(dig)) return false;
            // update reversed number
            reversed += rotation_map[dig] * place_val;
            place_val /= 10;
        }
        // return if reversed number is not equal to n
        return reversed != n;
    }
};

int main(){
    Solution mySolution;
    int testN = 89;
    bool result = mySolution.confusingNumber(testN);
    std::cout<<result<<std::endl;
    return 0;
}