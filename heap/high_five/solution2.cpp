class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // min heap
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> marks;
        for(auto& el : items){
            int id = el[0];
            int score = el[1];
            marks[id].push(score);
            if(marks[id].size() > 5) marks[id].pop();
        }
        vector<vector<int>> result;
        for(auto& [student, score_q] : marks){
            int total_score = 0;
            while(!score_q.empty()){
                total_score += score_q.top();
                score_q.pop();
            }
            result.push_back({student, total_score/5});
        }
        sort(result.begin(), result.end());
        return result; 
    }
};