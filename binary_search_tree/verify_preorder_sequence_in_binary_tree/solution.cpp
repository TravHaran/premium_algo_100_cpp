#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        vector<int> stack;
        int lower = INT_MIN;
        for(auto& el : preorder){
            while(!stack.empty() && el > stack.back()) {
                lower = stack.back();
                stack.pop_back();
            }
            if(el < lower) return false;

            stack.push_back(el);
        }
        return true;
    }
};