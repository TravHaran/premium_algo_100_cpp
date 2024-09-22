class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int minOne = INT_MAX, minTwo = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            minOne = min(minOne, nums1[i]);
            minTwo = min(minTwo, nums2[i]);
        }
        return minTwo - minOne;
    }
};