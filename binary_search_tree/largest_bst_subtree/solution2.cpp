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
    int largestBSTSubtree(TreeNode* root) {
        int max_val = INT_MIN, min_val = INT_MAX;
        int count = 0;
        postorder(root, count, max_val, min_val);
        return count;
    }

    int postorder(TreeNode* root, int& count, int& max_val, int& min_val){
        if(!root) return 0;
        // need to check left and right subtree
        int l_max = INT_MIN, r_min = INT_MAX;
        int left_count = postorder(root->left, count, l_max, min_val);
        int right_count = postorder(root->right, count, max_val, r_min);
        // if either left or right subtree is not bst we the current subtree isn't
        if(left_count < 0 || right_count < 0) return -1;
        // we know that a node is the root of a bst if it's 
        // value is greater than the left max and less than the right min
        if(root->val <= l_max || root->val >= r_min) return -1;
        // update min values in current tree
        min_val = min(min_val, root->val);
        max_val = max(max_val, root->val);
        int cur_count = left_count + right_count + 1;
        count = max(count, cur_count);
        return cur_count;
    }
};