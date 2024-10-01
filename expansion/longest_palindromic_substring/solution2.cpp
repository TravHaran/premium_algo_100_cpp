class Solution {
private:
    string prepare_string(string& s){
        // we want to add '#' between each character
        string new_s = "";
        for(auto& el : s) new_s += (string)"#" + el;
        return new_s+"#";
    }
    vector<int> manachers(string& s){
        int n = s.size();
        vector<int> d(n, 0);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(i <= r){
                int j = (2*l)-i;
                d[i] = min(r-i, d[j]);
            }
            int j = i+d[i]+1, k = i-d[i]-1;
            while(k >= 0 && j < n && s[k]==s[j]){
                d[i]++;
                j++;
                k--;
            }
            if(i+d[i] > r){
                r = i+d[i];
                l = i;
            }
        }
        return d;
    }

public:
    // Time: O(n), Space: O(n)
    string longestPalindrome(string s){
        // modify string to deal with even/odd parity
        s = prepare_string(s);
        // find all sub-palindromes with manacher's algo
        vector<int> palindromes = manachers(s);
        int centre_idx = 0, max_radius = 0;
        // find longest palindrome
        for(int i = 0; i < palindromes.size(); i++){
            if(palindromes[i] > max_radius){
                max_radius = palindromes[i];
                centre_idx = i;
            }
        }
        int l = centre_idx - max_radius, r = centre_idx + max_radius;
        string longest = s.substr(l, r-l);
        //remove special char '#' from answer
        string ans;
        for(auto& el : longest) if(el != '#') ans += el;
        return ans;
    }
};