class Solution {
private:
    // INSERTION SORT 
    // Time: O(n^2), Space: O(1)
    void insertionSort(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            int j = i;
            while(j > 0 && nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                j--;
            }
        }
    }

    // MERGE SORT
    // Time: O(nlogn), Space: O(n)
    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r) return; // base case
        int m = (l + r)/2;
        mergeSort(nums, l, m); // sort left half
        mergeSort(nums, m+1, r); // sort right half
        // merge sorted halves
        merge(nums, l, m, r);
    }

    void merge(vector<int>& nums, int l, int m, int r){
        // the first half is defined by l to m
        // second half is defined by m+1 to r
        vector<int> L = {nums.begin()+l, nums.begin()+m+1};
        vector<int> R = {nums.begin()+m+1, nums.begin()+r+1};

        // use three pointers
        int p1 = 0; // pointer to first half
        int p2 = 0; // pointer to second half
        int i = l; // array insert position
        // merge by inserting smallest value
        while(p1 < L.size() && p2 < R.size()){
            nums[i] = (L[p1] <= R[p2]) ? L[p1++] : R[p2++];
            i++;
        }
        // merge left over elements
        while(p1 < L.size()) nums[i++] = L[p1++];
        while(p2 < R.size()) nums[i++] = R[p2++];
    }

    // QUICK SORT
    // Time: O(nlogn), Space: O(logn)
    int medianOfThree(vector<int>& nums, int s, int r){
        int mid = (s+r)/2;
        if(nums[s] > nums[mid]) swap(nums[s], nums[mid]);
        if(nums[s] > nums[r]) swap(nums[s], nums[r]);
        if(nums[mid] > nums[r]) swap(nums[mid], nums[r]);
        return mid;
    }

    void quickSort(vector<int>& nums, int s, int r){
        // base case
        if(s>=r) return;
        // chose pivot using median of three
        int p = medianOfThree(nums, s, r);
        swap(nums[p], nums[r]); // Move the median element to the end as the pivot
        p = r;
        // partition
        int l = s;
        for(int i = l; i < r; i++){
            if(nums[i] < nums[p]){
                // swap
                swap(nums[l], nums[i]);
                l++;
            }
        }
        // place partition in correct spot
        swap(nums[l], nums[p]);
        // recursively partition left and right
        // ignore our pivot element at position l
        quickSort(nums, s, l-1); 
        quickSort(nums, l+1, r);
    }

    // HEAP SORT
    // Time: O(nlogn), Space: O(n)
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < n && nums[largest]<nums[left]) largest = left;
        if(right < n && nums[largest]<nums[right]) largest = right;
        if(largest!=i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void buildHeap(vector<int>& nums){
        int n = nums.size();
        int start = (n/2)-1;
        for(int i = start; i >= 0; i--){
            heapify(nums, n, i);
        }

    }

    void heapSort(vector<int>& nums){
        int n = nums.size();
        buildHeap(nums);
        for(int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, --n, 0);
        }
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        // insertionSort(nums);
        // mergeSort(nums, l, r);
        // quickSort(nums, l, r);
        heapSort(nums);
        return nums;
    }
};