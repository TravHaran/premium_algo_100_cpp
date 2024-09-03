
class Solution {
public:
    int minKnightMoves(int x, int y) {
        // A* Search Algorithm
        if(x==0 && y==0) return 0;
        vector<vector<int>> moves = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
        priority_queue<tuple<int, int, pair<int, int>>, vector<tuple<int, int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({euclidean(0, 0, 0, x, y), 0, {0, 0}});
        unordered_set<string> seen = {hash(0, 0)};
        int cur_x = 0, cur_y = 0;
        x= abs(x);
        y = abs(y);
        while(!minHeap.empty()){
            tuple<int, int, pair<int, int>> entry = minHeap.top();
            int steps = get<1>(entry);
            cur_x = get<2>(entry).first;
            cur_y = get<2>(entry).second;
            minHeap.pop();
            if(cur_x==x && cur_y==y) return steps;
            for(auto& m : moves){
                int nx = cur_x + m[0];
                int ny = cur_y + m[1];
                if(!seen.count(hash(nx, ny)) && nx >= -1 && ny>=-1){
                    minHeap.push({euclidean(steps +1, nx, ny, x, y), steps+1,{nx, ny}});
                    seen.insert(hash(nx, ny));
                }
            }
            
        }
        return 0;
    }

    int euclidean(int steps, int cur_x, int cur_y, int target_x, int target_y){
        return steps*3+(abs(target_x - cur_x)+ abs(target_y - cur_y));
    }

    string hash(int x, int y){
        return format("{}-{}", x, y);
    }
};