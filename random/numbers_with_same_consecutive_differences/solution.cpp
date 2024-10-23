class Solution {
private:
    // Helper function to get the length of a number
    int getLength(int num) {
        int length = 0;
        while (num > 0) {
            num /= 10;
            length++;
        }
        return length;
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> res;
        // Start with digits from 1 to 9
        for (int i = 1; i <= 9; i++) {
            bfs(i, n, k, res);
        }
        return vector<int>(res.begin(), res.end());
    }

    void bfs(int num, int n, int k, std::unordered_set<int>& res) {
        queue<int> q;
        q.push(num);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // If we've reached the required length, store the number
            if (getLength(curr) == n) {
                res.insert(curr);
                continue; // No need to process further for this number
            }

            // Get the last digit of the current number
            int last_digit = curr % 10;

            // Calculate the next possible digits
            if (last_digit + k < 10) {
                q.push(curr * 10 + (last_digit + k)); // Construct next number directly
            }
            if (k != 0 && last_digit - k >= 0) { // Check if k is not zero to avoid duplicate work
                q.push(curr * 10 + (last_digit - k)); // Construct next number directly
            }
        }
    }
};
