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
    vector<vector<int>> leaves;
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        return leaves;
    }

    int getHeight(TreeNode* node){
        if(!node) return 0;
        int height = 1;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        int curHeight = height + max(leftHeight, rightHeight);
        // create space for node located at `currHeight` if not already exists
        if(leaves.size()==curHeight-1) leaves.push_back({});
        // insert the value at the correct position in the solution array
        leaves[curHeight-1].push_back(node->val);
        return curHeight;
    }
};