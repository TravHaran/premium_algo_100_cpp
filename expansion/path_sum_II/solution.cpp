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
    void dfs(TreeNode* node, int targetSum, vector<int>& path){
        if(!node) return;
        targetSum -= node->val;
        path.push_back(node->val);
        // check if node is a leaf node & if we reached the targetSum
        if(targetSum==0 && !node->left && !node->right) res.push_back(path);
        if(node->left){
            dfs(node->left, targetSum, path);
            path.pop_back(); // Backtrack after exploring left subtree
        }
        if(node->right){
            dfs(node->right, targetSum, path);
            path.pop_back(); // Backtrack after exploring right subtree
        }
    }
    
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> source = {};
        dfs(root, targetSum, source);
        return res;
    }
};