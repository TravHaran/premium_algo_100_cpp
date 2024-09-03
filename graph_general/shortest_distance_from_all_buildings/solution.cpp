class Solution {
public:
    int OBSTACLE = 2;
    int LAND = 0;
    int HOUSE = 1;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int shortestDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> lands;
        int total_houses = 0;
        int R = grid.size();
        int C = grid[0].size();
        // create a list of all the empty lands
        // keep count of the total_houses in the grid
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(grid[r][c]==LAND) lands.push_back({r, c});
                else if(grid[r][c]==HOUSE) total_houses++;
            }
        }
        // for each empty land we want to count how many steps as required to reach all houses
        // run bfs on each empty land
        int min_dist = INT_MAX;
        for(auto& l : lands){
            int d = bfs(l, grid, total_houses, R, C);
            min_dist = min(min_dist, d);
        }
        return min_dist==INT_MAX ? -1 : min_dist;
    }

    int bfs(pair<int, int> land, vector<vector<int>>& grid, int houses, int R, int C){
        // initialize variable to keep count of houses we encounter
        int house_count = 0;
        int distance_sum = 0;
        // initialize queue with starting point
        deque<pair<int, int>> q = {land};
        // initialize a set to make sure we dont encounter visited coordinates
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        // unordered_set<string> seen = {hash(land.first, land.second)};
        int steps = 0, cur_x, cur_y;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto entry = q.front();
                q.pop_front();
                cur_x = entry.first;
                cur_y = entry.second;
                if(grid[cur_x][cur_y]==HOUSE){
                    house_count++;
                    distance_sum += steps;
                    continue;
                }
                
                for(auto& d : dirs){
                    int new_x = cur_x + d[0];
                    int new_y = cur_y + d[1];
                    // if this coordinate is within bounds
                    // not seen before
                    // not an obstacle
                    if(min(new_x, new_y) >= 0 && new_x < R && new_y < C 
                        && !seen[new_x][new_y] 
                        && grid[new_x][new_y]!=OBSTACLE){
                            q.push_back({new_x, new_y});
                            seen[new_x][new_y]=true;
                    }
                }
            }
            steps++;
        }
        if(house_count!=houses){
            for(int r = 0; r < R; r++){
                for(int c = 0; c < C; c++){
                    if(grid[r][c]==0 && seen[r][c]){
                        grid[r][c] = 2;
                    }
                }
            }
            return INT_MAX;
        }
        return distance_sum;
    }      
};