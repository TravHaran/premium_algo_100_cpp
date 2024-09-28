class Solution {
private:
    int binarySearch(int n, vector<int>& decks){
        // search for the spot to place n
        int l = 0, r = decks.size()-1;
        while(l < r){
            int mid = (l + r)/2;
             // If n matches an element, return its position
            if(decks[mid]==n) return mid;
            // If n is greater than the mid element, search right
            else if(decks[mid]< n) l = mid+1;
            // Otherwise, search left
            else r = mid;
        }
        // return the lowerbound position where n should be inserted
        return l;
    }

public:
    // Patience Sort
    // Time: O(nlogn), Space: O(n)
    int lengthOfLIS(vector<int>& nums) {
        // initialize an array to represent each card deck
        // you can only add a lower card value to each deck
        vector<int> decks;
        for(auto& n : nums){
            // If 'n' is larger than all elements in 'decks', create a new "deck" (subsequence)
            if(decks.empty() || n > decks.back()) decks.push_back(n);
            // Otherwise, replace the first element in 'decks' that is greater than or equal to 'n'
            else decks[binarySearch(n, decks)] = n;
        }
        // The size of 'decks' represents the length of the longest increasing subsequence
        return decks.size();
    }
};