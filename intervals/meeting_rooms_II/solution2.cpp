#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto& el : intervals){
            starts.push_back(el[0]);
            ends.push_back(el[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s(0);
        int e(0);
        int count(0);
        while(s < starts.size()){
            if(starts[s] < ends[e]) count++; 
            else e++;
            s++;
        }
        return count;
    }
};