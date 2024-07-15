#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        for(auto& el : arr){
            set.insert(el);
        }
        int count(0);
        for(auto& n : arr){
            if(set.count(n+1)) count++;
        }
        return count;
    }
};