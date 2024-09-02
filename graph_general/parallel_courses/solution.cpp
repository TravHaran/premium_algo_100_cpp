class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // create an adjacency list graph & update inegrees
        vector<int> indegree(n+1,0); // In-degree of each course
        unordered_map<int, vector<int>> m;
        for(auto& edge : relations){
            m[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        // initialize the queue for BFS with nodes that have zero in-degrees
        deque<int> q;
        for(int i=1; i <=n; i++){
            if(indegree[i]==0) q.push_back(i);
        }
        int semesters = 0, taken_courses = 0;
        while(!q.empty()){
            int size = q.size();
            taken_courses += size;
            semesters++;
            for(int i = 0; i < size; i++){
                int course = q.front();
                q.pop_front();
                
                for(auto& c : m[course]){
                    indegree[c]--;
                    if(indegree[c]==0){
                        q.push_back(c);
                    }
                }
            }
        }
        if(taken_courses==n) return semesters;
        return -1;
    }
};