class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0) {
                carry += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                carry += num2[j] - '0';
                j--;
            }
            ans += (carry % 10) + '0';
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};