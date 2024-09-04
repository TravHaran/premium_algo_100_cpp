class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<pair<int, int>>> worker_pairs;
        for(int i = 0; i < workers.size(); i++){
            // Add all the bikes with their distances from the current worker
            vector<pair<int, int>> bike_pairs;
            for(int j = 0; j < bikes.size(); j++){
                int dist = manhattan(workers[i], bikes[j]);
                bike_pairs.push_back({dist, j});
            }
            // Sort the bike_pairs for the current worker in reverse order.
            sort(bike_pairs.begin(), bike_pairs.end(), greater<>());
            auto closest_pair = bike_pairs.back();
            bike_pairs.pop_back();
            // For each worker, add their closest bike to the priority queue
            pq.push({closest_pair.first, i, closest_pair.second});
            // Store the remaining options for the current worker in worker-pair list
            worker_pairs.push_back(bike_pairs);
        }
        vector<int> result(workers.size(), -1);
        vector<bool> bike_taken(bikes.size(), false);

        while(!pq.empty()){
            // Pop the pair with smallest distance
            auto[dist, worker_idx, bike_idx] = pq.top();
            pq.pop();
            if(!bike_taken[bike_idx]){
                // If the bike is free, assign the bike to the worker
                result[worker_idx] = bike_idx;
                bike_taken[bike_idx] = true;
            } else {
                // otherwise, push the next smallest pair for this worker onto the q
                auto next_pair = worker_pairs[worker_idx].back();
                worker_pairs[worker_idx].pop_back();
                pq.push({next_pair.first, worker_idx, next_pair.second});
            }
        }
        return result;
    }

    int manhattan(vector<int> x, vector<int> y){
        return abs(x[0]-y[0]) + abs(x[1]-y[1]);
    }
};