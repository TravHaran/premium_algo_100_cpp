class Solution {
public:
    int minimumPushes(string word) {
        // get frequency count
        unordered_map<char, int> freq;
        for(auto& c : word){
            freq[c]++;
        }
        // letter with higher frequency have higher priority
        // rank unique letters with highest frequency using maxheap
        priority_queue<int> pq;
        for(auto& [letter, count] : freq){
            pq.push(count);
        }
        int idx = 0;
        int moves = 0;
        while(!pq.empty()){
            int count = pq.top();
            pq.pop();
            moves += (1 + (idx/8))*count;
            idx++;
        }
        return moves;
    }
};