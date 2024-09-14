#include <ranges>

class Leaderboard {
public:
    map<int, int> scores;
    unordered_map<int, int> players;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int pre_score = 0;
        // player already had a score
        if(players.count(playerId)){
            // get the previous score of the player
            pre_score = players[playerId];
            // remove the previous score from the scores map
            scores[pre_score]--;
            if(scores[pre_score]<1) scores.erase(pre_score);
        }
        // update scores map with current score
        scores[pre_score + score]++;
        // update player's current score
        players[playerId] = pre_score + score;
        
    }
    
    int top(int K) {
        int sum = 0;
        for(auto& [key, val] : scores | std::views::reverse){
            int use = min(K, val);
            sum += (key * use);
            K -= use;
            if(K==0) break;
        }
        return sum;
    }
    
    void reset(int playerId) {
        // get the current player's score
        int s = players[playerId];
        // remove player
        players.erase(playerId);
        // remove their score
        scores[s]--;
        if(scores[s]<1) scores.erase(s);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */