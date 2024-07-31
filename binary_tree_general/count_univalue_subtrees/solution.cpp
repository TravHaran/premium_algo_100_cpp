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
    int count = 0;
    int countUnivalSubtrees(TreeNode* root) {
        // leaf nodes count as univalue subtree
        _dfs(root);
        return count;  
    }

    bool _dfs(TreeNode* node){
        if(!node) return true;
        bool isLeftUniValue = _dfs(node->left);
        bool isRightUniValue = _dfs(node->right);
        if(isLeftUniValue && isRightUniValue){
            if(node->left && node->left->val != node->val) return false;
            if(node->right && node->right->val != node->val) return false;
            count++;
            return true;
        }
        return false;
    }
};