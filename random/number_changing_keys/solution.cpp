class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for(int i = 0; i < s.size()-1; i++){
            if(tolower(s[i])!=tolower(s[i+1])) count++;
        }
        return count;
        
    }
};