class Codec {
public:
    vector<int> string_count;
    string encoded;
    vector<string> decoded;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string_count = {};
        encoded = "";
        for(auto& s : strs){
            string_count.push_back(s.size());
            encoded += s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        decoded = {};
        int l, r = 0 , next_l = 0;
        for(int i = 0; i < string_count.size(); i++){
            l = next_l;
            r = string_count[i];
            next_l += string_count[i];
            decoded.push_back(s.substr(l, r));
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));