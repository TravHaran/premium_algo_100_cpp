using namespace std;

class Solution {
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int ROWS = maze.size();
        int COLS = maze[0].size();
        // initialize set to store visited nodes
        set<pair<int, int>> visited;
        // initialize a vector to store all directions we can travel from a node
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // run bfs
        deque<pair<int, int>> q = {{start[0], start[1]}};
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop_front();
            if(visited.count(node)) continue;
            visited.insert(node);
            if(node.first == destination[0] && node.second == destination[1]) return true;
            for(auto& d : dirs){
                int r = node.first;
                int c = node.second;
                while((r>=0 && r < ROWS) && (c>=0 && c < COLS) && maze[r][c]!=1){
                    r += d[0];
                    c += d[1];
                }
                q.push_back({r-d[0], c-d[1]});
            }

        }
        return false;
    }
}