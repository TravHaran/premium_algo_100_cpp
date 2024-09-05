class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        // to conver int to string to_string(), convert string to int stoi()
        int size = nums.size();
        int sum = 0;
        for(auto& n : nums){
            sum += encrypt(n);
        }
        return sum;
    }

    int encrypt(int n){
        string s = to_string(n);
        int largest = INT_MIN;
        for(auto c : s){
            int dig = c-'0'; // convert char to int
            largest = max(dig, largest);
        }
        int times = 1;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            result += largest * times;
            times *= 10;
        }
        return result;
    }
};