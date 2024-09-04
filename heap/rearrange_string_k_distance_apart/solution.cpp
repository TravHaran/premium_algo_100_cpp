class Solution {
public:
    string rearrangeString(string s, int k) {
        string result;
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> freq;
        // create a frequency map of the characters in the string
        for(auto& c : s){
            freq[c]++;
        }
        // Insert the characters with their frequencies in the max heap.
        for(auto& [c, count] : freq){
            pq.push({count, c});
        }
        // This queue stores the characters that cannot be used now.
        deque<pair<int, int>> busy;
        while(result.size()!=s.size()){
            int index = result.size();
            // Insert the character that could be used now into the heap.
            if(!busy.empty()){
                auto [idx, c] = busy.front();
                if(index - idx >= k){
                    pq.push({freq[c], c});
                    busy.pop_front();
                }
            }
            // If the heap is empty, it implies no character can be used at this index.
            if (pq.empty()) return "";
            auto [count, c] = pq.top();
            pq.pop();
            result.push_back(c);
            // Insert the used character into busy queue with the current index.
            freq[c]--;
            if(freq[c] > 0) busy.push_back({index, c});
        }
        return result;
    }
};