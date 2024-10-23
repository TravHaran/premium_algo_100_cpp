#include <vector>
using namespace std;

class Solution {
public:
    // Optimized binary search to find the insertion position
    inline int binarySearchInsert(vector<int>& sequence, int value, int size) {
        int left = 0, right = size;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (sequence[mid] < value) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    // Intuition: We find the largest mountain by calculating:
    // LIS ending at each element and LDS starting at each element.
    // Then, for each peak, the mountain length is LIS[i] + LDS[i] - 1.
    // Result: n - maxMountain gives the minimum removals.
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // invalid mountain array
        vector<int> lis(n, 1), temp(n);
        int tempSize = 0, maxMountain = 0;
        // Compute LIS
        for (int i = 0; i < n; ++i) {
            int pos = binarySearchInsert(temp, nums[i], tempSize);
            temp[pos] = nums[i];
            if (pos == tempSize) ++tempSize;
            lis[i] = tempSize;
        }
        // Compute LDS and find max mountain length
        tempSize = 0;
        for (int i = n - 1; i >= 0; --i) {
            int pos = binarySearchInsert(temp, nums[i], tempSize);
            temp[pos] = nums[i];
            if (pos == tempSize) ++tempSize;
            if (lis[i] > 1 && tempSize > 1) {
                maxMountain = max(maxMountain, lis[i] + tempSize - 1);
            }
        }
        return n - maxMountain;
    }
};