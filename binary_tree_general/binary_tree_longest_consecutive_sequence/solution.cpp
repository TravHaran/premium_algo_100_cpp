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
    int maxLen = 0;
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        _dfs(root, INT_MIN, 1);
        return maxLen;
    }

    void _dfs(TreeNode* node, int prev, int count){
        if(!node) return;
        count = (node->val == prev+1)? count+1 : 1;
        maxLen = max(maxLen, count);
        _dfs(node->left, node->val, count);
        _dfs(node->right, node->val, count);
    }
};