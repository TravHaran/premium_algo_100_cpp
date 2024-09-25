class Solution {
    // Topological Sort
private:
    pair<char, char> compare(const string& a, const string& b) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return {a[i], b[i]};
        }
        return {0, 0}; // Indicate no difference
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        
        // Initialize unique characters
        for (const auto& word : words) {
            for (const auto& ch : word) {
                indegree[ch] = 0;
            }
        }

        // Build graph only comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            auto [l1, l2] = compare(words[i], words[i + 1]);
            if (l1 != l2) {
                adj[l1].push_back(l2);
                indegree[l2]++;
            } else if (l1 == 0 && words[i].size() > words[i + 1].size()) {
                return ""; // Invalid case: larger word comes before smaller
            }
        }

        // BFS
        deque<char> q;
        for (auto& [key, val] : indegree) {
            if (val == 0) q.push_back(key);
        }

        string res;
        while (!q.empty()) {
            char node = q.front();
            q.pop_front();
            res += node;
            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push_back(neighbor);
            }
        }

        // If result doesn't contain all unique characters, there's a cycle
        return res.size() == indegree.size() ? res : "";
    }
};
