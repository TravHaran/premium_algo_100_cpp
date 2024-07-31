class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        deque<int> q;
        vector<int> result;
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < ppid.size(); i++){
            if(ppid[i]==0) continue;
            graph[ppid[i]].push_back(pid[i]);
        }

        q.push_back(kill);
        while(!q.empty()){
            int id = q.front();
            q.pop_front();
            result.push_back(id);
            for(auto& child : graph[id]){
                q.push_back(child);
            }
        }
        return result;
    }
};