class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    vector<bool> seeing;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build forward adjacency list. If destination has any outgoing edges, return early.
        for(auto& e : edges){
            if(e[0]==destination) return false;
            graph[e[0]].push_back(e[1]);
        }
        seen = vector<bool>(n);
        seeing = vector<bool>(n);
        // perform dfs form source
        return dfs(source, destination);
        

    }

    bool dfs(int i, int destination){
        // If we already know this leads to our destination, return true now.
        if(seen[i]) return true;
        // If this is a node on our current path, we've found a loop. Return false.
        if(seeing[i]) return false;
        // If this is a sink node, return appropriately.
        if(graph[i].empty()) return i == destination;
        // Mark this node to find loops further along the path.
        seeing[i] = true;
        // Query the outgoing paths. If we find an invalid path, return early.
        for(auto& el : graph[i]){
            if (!dfs(el, destination)) return false;
        }
        // If all outgoing paths are valid, return true and cache that result.
        return seen[i] = true;
    } 
};