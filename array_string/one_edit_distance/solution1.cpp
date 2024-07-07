#include <iostream>
#include <unordered_map>

class Solution {
    public:
        bool isOneEditDistance(std::string s, std::string t) {
            if (s == t) return false;
            // if (s.length() == t.length()) return false;
            // build char map of shorter string
            std::string shorter_str;
            std::string longer_str;
            (s.length() < t.length()) ? shorter_str = s : shorter_str = t;
            (s.length() < t.length()) ? longer_str = t : longer_str = s;
            bool one_edit = false;
            int idx = 0;
            if (s.length() == t.length()) {
                for(int i = 0; i < s.length(); i++){
                    char el = t[i];
                    if(el != s[i]){
                        if(one_edit) return false;
                        one_edit = true;
                    }
                }
            } else {
                for(int i = 0; i < longer_str.length(); i++){
                    char el = longer_str[i];
                    if(el != shorter_str[idx]){
                        if(one_edit) return false;
                        one_edit = true;
                    } else {
                        idx++;
                    } 
                }
            }
            return one_edit;   
    }
};

int main(){
    Solution mySolution;
    std::string testS = "a";
    std::string testT = "A";
    bool result = mySolution.isOneEditDistance(testS, testT);
    std::cout<<"one edit distance: "<<result<<std::endl;
}