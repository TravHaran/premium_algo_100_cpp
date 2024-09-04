/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

 // let l to y define the scope of our comparison
// if the scope length is even then we can compare two subarrays of equal size
    // when comparing two sub arrays of of equal size
    // if we find that the sum of one of them is greater than the other
    // then we know that the largest idx is in that subarray
// if the scope length is odd then we must compare two subarrays excluding the middle
    // in this case if we get that sum of both of them is equal we know the middle element
    // is our answer

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int size = reader.length();
        int l = 0, y = size-1;
        int scope_len, r, x;
        // if we break from this loop it means that binary search has 
        // converged on a single element which is the largest.
        while(l < y){
            scope_len = ((y-l)+1)/2;
            r = l + scope_len - 1;
            x = y - scope_len + 1;
            // compare subarray (l-r) and (x-y)
            int res = reader.compareSub(l, r, x, y);
            // if they are equal, then we know it must be the middle elemt
            if(res==0){
                return r+1;
            } else if(res == 1){
                // largest is in left subarray
                y = r;
            } else {
                // largest is in right subarray
                l = x;
            }
        }
        return l;
    }
};