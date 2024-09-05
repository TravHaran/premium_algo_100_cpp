class TicTacToe {
    // we will have two vectors
    // a vector of rows
    // a vector of columns
    // entries in both vectors will be a pair of integers
    // this entry will keep count of how many player1's and player2's there are in this row/col
    //then we will also have a vector<> for diagonal 1 and a vector for diagonal 2
    // at each move we determine if it falls in a the diagonals and update its player count
    // every time we make a move we update counts
    // if the count ever reaches n we return that the player won

public:
    vector<pair<int, int>> rows;
    vector<pair<int ,int>> cols;
    pair<int, int> diag1;
    pair<int, int> diag2;
    int N;
    TicTacToe(int n) {
        for(int i = 0; i < n; i++){
            rows.push_back({0, 0});
            cols.push_back({0, 0});
        }
        diag1 = {0, 0};
        diag2 = {0, 0};
        N = n; 
    }
    
    int move(int row, int col, int player) {
        // update row
        (player == 1) ? rows[row].first++ : rows[row].second++;
        // check if we won
        if (rows[row].first == N || rows[row].second == N) return player;
        // update col
        (player == 1) ? cols[col].first++ : cols[col].second++;
        // check if we won
        if (cols[col].first == N || cols[col].second == N) return player;
        // update diagonals
        if(row==col){
            (player == 1) ? diag1.first++ : diag1.second++;
            if (diag1.first == N || diag1.second == N) return player;
        }
        if(row==N-col-1){
            (player == 1) ? diag2.first++ : diag2.second++;
            if (diag2.first == N || diag2.second == N) return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */