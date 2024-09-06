class SnakeGame {
    // we need to store the snake
    // we can do this using an unordered set 
    // this set will contain all the coordinates that make up the snake
    // but every time we move we also will remove the tail of the snake
    // so we will also store the snake coordinates in a queue with the same length of the snake
    // every time we move the snake, we pop from the end of the queue and push the current head into the queue
    // if the head of the snake hits a part of its body or goes out of bounds
    // we return -1
    // else we return the length of the snake
    // we will hash the coordinates into a string to save memory
private:
    string hash(int x, int y){
        return format("{}~{}", x, y);
    }

public:
    deque<pair<int,int>> q;
    unordered_set<string> snake;
    int R;
    int C;
    int length;
    vector<vector<int>> food_locs;
    unordered_map<string, pair<int, int>> dirs;
    int food_idx;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        // width = # cols
        // height = # rows
        R = height;
        C = width;
        // initialize directions
        dirs = {{"U", {0, -1}}, {"D", {0, 1}}, {"R", {1, 0}}, {"L", {-1, 0}}};
        // initialize snake length of 1
        length = 1;
        food_locs = food;
        // initialize snake at top left corner (0, 0)
        q = {{0,0}};
        snake = {hash(0,0)};
        // start off with the first food item;
        food_idx = 0;
    }
    
    int move(string direction) {
        // get head position
        auto [x, y] = q.front();
        // compute new head position after move
        int new_x = x + dirs[direction].first;
        int new_y = y + dirs[direction].second;
        // check if this position is valid
            // if it hits the body or goes out of bounds return -1
            // else its valid
        auto [tail_x, tail_y] = q.back();
        string hashed_tail = hash(tail_x, tail_y);
        q.pop_back();
        snake.erase(hashed_tail);
        string hashed_head = hash(new_x, new_y);
        if(snake.count(hashed_head) || min(new_x, new_y) < 0 || new_x >= C || new_y >= R) return -1;
        // check if it hits a food block
            // if it does then we increase the snake size
            // we add the new head position to the front of the queue
            // we add the new head position to the unordered set
            // increment to the next food
        if(food_idx < food_locs.size() && new_x == food_locs[food_idx][1] && new_y == food_locs[food_idx][0]){
            q.push_back({tail_x, tail_y});
            snake.insert(hashed_tail);
            food_idx++;
        }
        // else if it doesn't hit a food block we move the snake
            // we pop from the end of the queue
            // we remove the popped element from the unordered set
            // we add the new head position to the front of the queue
            // we add the new head position to the unordered set
        q.push_front({new_x, new_y});
        snake.insert(hashed_head);
        return q.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */