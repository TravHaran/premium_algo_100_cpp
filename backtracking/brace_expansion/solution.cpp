class Solution {
private:
    void _expand(int idx, string temp){
        while(idx < temp.size() && temp[idx] != '.'){
            idx++;
        }
        if(idx==temp.size()) res.push_back(temp);
        else {
            sort(options[idx].begin(), options[idx].end());
            for(auto& opt : options[idx]){
                temp[idx] = opt;
                _expand(idx+1, temp);
            }
        }
    }

public:
    vector<string> res;
    unordered_map<int, vector<char>> options;
    vector<string> expand(string s) {
        int idx = -1;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='{'){
                temp += ".";
                idx++;
                i++;
                while(s[i]!='}'){
                    if(s[i]!=',') options[idx].push_back(s[i]);
                    i++;
                }
            } else {
                idx++;
                temp += s[i];
            }
        }
        _expand(0, temp);
        return res;
    }
};