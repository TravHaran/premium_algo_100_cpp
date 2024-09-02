class Solution {
public:
    int EMPTY = 2147483647;
    int GATE = 0;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int R = rooms.size();
        int C = rooms[0].size();
        deque<pair<int, int>> q;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(rooms[r][c]==GATE){
                    q.push_back({r, c});
                }
            }
        }
        int cur_x, cur_y;
        int steps = 0;
        while(!q.empty()){
            pair<int, int> entry = q.front();
            cur_x = entry.first;
            cur_y = entry.second;
            q.pop_front();
            for(auto& d : dirs){
                int new_x = cur_x + d[0];
                int new_y = cur_y + d[1];
                if(new_x >= 0 && new_x < R && new_y >=0 && new_y < C && rooms[new_x][new_y]==EMPTY){
                    q.push_back({new_x, new_y});
                    rooms[new_x][new_y] = rooms[cur_x][cur_y] + 1;
                } 
            }
        }
    }
};