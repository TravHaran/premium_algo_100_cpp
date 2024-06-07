#include <iostream>
#include <vector>

class Solution {
    public:
        void reverseWords(std::vector<char>& s) {
            std::vector<std::string> words;
            std::string cur_word = "";
            for(int i = s.size()-1; i >= -1; i--){
                char el = s[i];
                if(el == ' ' || i==-1){
                    words.push_back(cur_word);
                    cur_word = "";
                } else {
                    cur_word  = el + cur_word;
                }
            }
            std::vector<char> result;
            for(int i = 0; i < words.size(); i++){
                std::string word = words[i];
                std::cout<<word<<std::endl;
                for(auto& el: word) result.push_back(el);
                if(i!=words.size()-1) result.push_back(' ');
            }
            s = result;  
        }
};

int main(){
    Solution mySolution;
    std::vector<char> testS = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    mySolution.reverseWords(testS);
    std::vector<char> expected = {'b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e'};
    assert(testS == expected);
    return 0;
}