class StringIterator {
public:
    int idx;
    string s;
    pair<char, int> nextChar;
    StringIterator(string compressedString) {
        s = compressedString;
        idx = 0;
        nextChar = {'x', 0};
    }
    
    char next() {
        char l;
        if(nextChar.second == 0 && idx<s.size()){
            // get letter
            l = s[idx];
            idx++;
            // get count
            string count = "";
            while(idx < s.size() && isdigit(s[idx])){
                count.push_back(s[idx]);
                idx++;
            }
            int n = stoi(count);
            nextChar = {l, n-1};
        } else if(nextChar.second > 0){
            // get letter
            l = nextChar.first;
            nextChar.second--;
        } else {
            // idx is greater than string s, string is uncompressed
            return ' ';
        }
        return l;
    }
    
    bool hasNext() {
        return idx < s.size() || nextChar.second > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */