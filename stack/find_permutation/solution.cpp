#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> stack;
        vector<int> output;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='I') {
                stack.push_back(i+1);
                while(!stack.empty()){
                    output.push_back(stack.back());
                    stack.pop_back();
                }
            }
            else {
                stack.push_back(i+1);
            }
        }
        stack.push_back(s.size()+1);
        while(!stack.empty()){
            output.push_back(stack.back());
            stack.pop_back();
        }
        return output;
    }
};