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
    int maxVal = 0;
    int longestConsecutive(TreeNode* root) {
        _longest(root);
        return maxVal;
    }
    vector<int> _longest(TreeNode* node){
        if(!node) return {0, 0};
        int inr = 1, dcr = 1;
        if(node->left){
            vector<int> left = _longest(node->left);
            if(node->val == node->left->val + 1) dcr = left[1] + 1;
            else if(node->val == node->left->val - 1) inr = left[0] + 1;
        }
        if(node->right){
            vector<int> right = _longest(node->right);
            if(node->val == node->right->val + 1) dcr = max(dcr, right[1] + 1);
            else if(node->val == node->right->val - 1) inr = max(inr, right[0] + 1); 
        }
        maxVal = max(maxVal, inr + dcr - 1);
        return {inr, dcr};
    }
};