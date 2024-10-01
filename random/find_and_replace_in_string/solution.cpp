class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // create a hashmap of s indices where replacements need to occur
        unordered_map<int, int> idxMap;
        for(int i = 0; i < indices.size(); i++){
            string source = sources[i];
            string target = targets[i];
            string original_substring = s.substr(indices[i], source.size());
            // we know a replacement needs to occur if the source matches the original
            if(source==original_substring) idxMap[indices[i]] = i;
        }
        string result;
        // iterate through our string and make our replacements as need
        for(int i = 0; i < s.size(); i++){
            if(idxMap.count(i)){ // replacement required
                int idx = idxMap[i];
                result += targets[idx];
                i += sources[idx].size()-1;
            } else { // no replacement required
                result += s[i];
            }
        }
        return result;
    }
};