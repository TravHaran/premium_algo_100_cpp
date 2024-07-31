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
    double maxAvg = 0;
    double maximumAverageSubtree(TreeNode* root) {
        _dfs(root);
        return maxAvg;
    }

    vector<int> _dfs(TreeNode* node){
        if(!node) return {0, 0}; // {nodeCount, nodeSum}
        vector<int> leftSum = _dfs(node->left);
        vector<int> rightSum = _dfs(node->right);
        int totalCount = leftSum[0] + rightSum[0] + 1;
        int totalSum = leftSum[1] + rightSum[1] + node->val;
        double avg = (double)totalSum/totalCount;
        maxAvg = max(maxAvg, avg);
        return {totalCount, totalSum};
    }
};