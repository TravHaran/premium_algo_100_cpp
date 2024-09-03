class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort( items.begin( ), items.end( ), [ ]( const auto& i1, const auto& i2 )
        {
            if(i1[0] == i2[0]) return i1[1] > i2[1];
            else return i1[0] < i2[0];
        });
        vector<vector<int>> result;
        unordered_map<int, vector<int>> top;
        unordered_set<int> completed;
        for(auto& el : items){
            int id = el[0];
            int score = el[1];
            if(!completed.count(id)){
                top[id].push_back(score);
                if(top[id].size()==5) {
                    int cur_score = 0;
                    for(auto& s : top[id]){
                        cur_score += s;
                    }
                    result.push_back({id, cur_score/5});
                    completed.insert(id);
                } 
            }
        }
        return result; 
    }
};