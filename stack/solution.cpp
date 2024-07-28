#include <vector>
#include <string>

class Solution {
// PARSE THE STRING FROM RIGHT TO LEFT
// STORE THE CHOICES FOR EACH TERNARY EXPRESSION TO BE EVALUATED IN A STACK
// ONCE WE ENCOUNTER A TERNARY SYMBOL WE CHECK THE NEXT SYMBOL TO SEE IF ITS T OR F
// IF ITS T WE POP THE FIRST VALUE FROM THE STACK AND SAVE IT, THEN WE POP THE SECOND
// THEN WE PUSH THE SAVED VALUE ONTO THE STACK
// IF ITS F WE POP THE FIRST VALUE FROM THE STACK, THEN POP THE SECOND ONE AND SAVE IT
// THEN WE PUSH THE SAVED VALUE ONTO THE STACK
// IN ORDER TO STORE THE CHOICES IN THE STACK, WE WILL KEEP A VARIABLE TO SAVE THE CHAR
// IF WE ENCOUNTER A ":" THEN WE KNOW TO PUSH THE VARIABLE ONTO THE STACK
public:
    string parseTernary(string expression) {
        int n = expression.size();
        char choice;
        char decision;
        vector<char> stack;
        for(int i = n-1; i >= 0; i--){
            if(expression[i] != ':' && expression[i] !='?'){
                stack.push_back(expression[i]);
            } else if(expression[i]=='?'){
                decision = expression[i-1];
                if(decision=='T'){
                    // we choose the first option
                    choice = stack.back();
                    stack.pop_back();
                    stack.pop_back();
                } else {
                    // decision is F, so we choose the 2nd option
                    stack.pop_back();
                    choice = stack.back();
                    stack.pop_back();
                }
                i--;
                stack.push_back(choice);
            }
        }
        return string(1, choice); 
    }
};