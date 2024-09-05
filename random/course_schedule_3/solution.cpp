class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // c[0] duration, c[1] last day
        // rank courses by smallest lastDay, i.e. the most urgent course
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        // we will track the max courses we can take with a maxheap
        // this will allow us to remove the course with the largest duration if we exceed the last day for a course
        priority_queue<int> pq;
        int time = 0;
        for(auto& c : courses){
            int duration = c[0];
            int last_day = c[1];
            pq.push(duration);
            time += duration;
            if(time > last_day){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};