class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);
        unordered_map<int, vector<int>> graph;
        // build adjacency list
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // run dfs
        int count(0);
        for(int i = 0; i < n; i++){
            if(!seen[i]){
                count++;
                dfs(i, seen, n, graph);
            }
        }
        return count;
    }

    void dfs(int target, vector<bool>& seen, int n, unordered_map<int, vector<int>>& graph){
        seen[target] = true;
        vector<int> children = graph[target];
        for(auto& child : children){
            if(!seen[child]){
                dfs(child, seen, n, graph);
            } 
        }
    }
};