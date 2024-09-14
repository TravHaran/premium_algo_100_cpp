class Solution {
public:
    bool isArmstrong(int n) {
        string num = to_string(n);
        int sum = 0;
        int k = num.size();
        for(auto& c : num){
            int val = c - '0';
            sum += pow(val, k);
        }
        return sum == n;
    }
};