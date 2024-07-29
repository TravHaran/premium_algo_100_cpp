#include <deque>
#include <vector>
using namespace std;

class FirstUnique {
    // maintain a frequency map of the elements in the queue
    // store unique elements in a queue
public:
    unordered_map<int, int> freq;
    deque<int> unique;
    FirstUnique(vector<int>& nums) {
        for(auto& el : nums){
            add(el);
        }
    }
    
    int showFirstUnique() {
        // If there is no unique number return -1
        return unique.empty()?-1:unique.front();
    }
    
    void add(int value) {
        // After added the value, if the count of the value is 1, add it to queue
        freq[value]++;
        if(freq[value]==1) unique.push_back(value);
        // remove the number which is no longer unique
        while(!unique.empty() && freq[unique.front()]>1) unique.pop_front();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */