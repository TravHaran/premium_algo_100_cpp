/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int count = 1;
        int idx = -1;
        int query1234 = reader.query(1, 2, 3, 4);
        int query0123 = reader.query(0, 1, 2, 3);
        // compare idx 0 and 1
        (reader.query(0, 2, 3, 4)== query1234) ? count++ : idx = 1;
        // compare idx 0 and 2
        (reader.query(0, 1, 3, 4)==query1234) ? count++ : idx = 2;
        // compare idx 0 and 3
        (reader.query(0, 1, 2, 4)==query1234) ? count++ : idx = 3;
        // compare rest of elements
        for(int i = 4; i < n; i++){
            (query0123==reader.query(1, 2, 3, i)) ? count++ : idx = i;
            if(count > n/2) return 0; // return early if we find majority
        }
        // if we find a tie return -1 else return the latest index with a different value
        return (n%2==0 && count == n/2) ? -1 : idx;
    }
};