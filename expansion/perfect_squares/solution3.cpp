class Solution {
    // Treat problem like a shortest path problem
    // we're looking for the minimum number of perfect square to give n
public:
    int numSquares(int n) {
        // Step 1: Generate all perfect squares <= n
        vector<int> perfects;
        for (int i = 1; i * i <= n; ++i) {
            perfects.push_back(i * i);
        }
        // BFS initialization
        deque<int> q{n};
        vector<bool> visited(n+1, false);
        visited[n] = true;
        int level = 0;
        while(!q.empty()){
            level++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int remainder = q.front();
                q.pop_front();
                // subtract each perfect square from remainder
                for(auto& square : perfects){
                    int newRemainder = remainder - square;
                    if(newRemainder==0) return level; // we found the solution
                    if(newRemainder < 0) break; // No need to check further
                    if(!visited[newRemainder]){
                        visited[newRemainder] = true;
                        q.push_back(newRemainder);
                    }

                }
            }
        }
        return level;
    }
};