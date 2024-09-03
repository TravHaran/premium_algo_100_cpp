class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
        int cost = 0;
        while(q.size()>1){
            // combine sticks
            int stick1 = q.top();
            q.pop();
            int stick2 = q.top();
            q.pop();
            int length = stick1 + stick2;
            // update cost
            cost += length;
            q.push(length);
        }
        return cost;
    }
};