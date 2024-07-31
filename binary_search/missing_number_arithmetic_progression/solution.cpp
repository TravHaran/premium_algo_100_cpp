class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        // compute diff
        int diff = (arr.back() - arr.front())/n;
        // use binary search to find missing number
        int hi = n-1;
        int low = 0;
        while(low < hi){
            int mid = (low + hi)/2;
            if(arr[mid]== arr.front()+(mid*diff)){
                low = mid+1;
            } else {
                // a number is missing including mid itself
                hi = mid;
            }
        }
        // Index `lo` will be the position with the first incorrect number.
        // Return the value that was supposed to be at this index.
        return arr.front() + (low*diff);
        
    }
};