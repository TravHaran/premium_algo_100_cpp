#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // we will store the meeting end times in a min heap
        // we will iterate through the intervals checking the start time
        // if the start time is less than top element in minheap (the lowest end time)
        // this means that there is an overlap and we will need another room
        // so we add the end time of the current interval to the minheap
        // if the start time is greater than the top element in minheap
        // this means that there is no overlap so we dont need to add another room
        // however we will replace the top minheap value with the end time of the current interval
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int> meeting = intervals[i];
            if(meeting[0] < minHeap.top()){
                minHeap.push(meeting[1]);
            } else {
                minHeap.pop();
                minHeap.push(meeting[1]);
            }
        }
        return minHeap.size();
    }
};