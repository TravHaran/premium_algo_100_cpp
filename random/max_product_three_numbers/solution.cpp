class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // minheap to store top 3 max elements
        priority_queue<int, vector<int>, greater<int>> max_elems;
        // top 2 min elements
        int small_1 = INT_MAX, small_2;
        for(int i = 0; i < nums.size(); i++){
            max_elems.push(nums[i]);
            if(max_elems.size()>3) max_elems.pop();
            if(nums[i] < small_1){
                small_2 = small_1;
                small_1 = nums[i];
            } 
            else if(nums[i] < small_2){
                small_2 = nums[i];
            }
        }
        // our result is either the product of top 3 max
        int top_max;
        int opt1 = 1;
        while(!max_elems.empty()){
            top_max = max_elems.top();
            opt1 *= top_max;
            max_elems.pop();
        }
        // or the product of top two min and top max
        int opt2 = top_max * small_1 * small_2;
        return max(opt1, opt2);
    }
};