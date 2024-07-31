/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<pair<double, int>> pq;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // use a maxHeap, priority_queue is a maxHeap by default
        vector<int> result;
        _dfs(root, target, k);
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    void _dfs(TreeNode* node, double target, int k){
        if(!node) return;
        pq.push({abs(node->val - target), node->val});
        if(pq.size() > k) pq.pop();
        _dfs(node->left, target, k);
        _dfs(node->right, target, k);
    }
};