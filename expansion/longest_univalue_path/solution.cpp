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
private:
    // Helper function to perform depth-first search (DFS)
    int dfs(TreeNode* node, int parent) {
        // If the current node is null, return 0 (base case)
        if (!node) return 0;

        // Recursively find the longest univalue path in the left and right subtrees
        int left = dfs(node->left, node->val);    // Check the left child
        int right = dfs(node->right, node->val);  // Check the right child

        // Update the result with the longest univalue path found so far
        // The path can be formed by adding the left and right counts
        res = max(res, left + right);

        // If the current node's value matches its parent's value, 
        // return the length of the longest path extending from this node
        return (node->val == parent) ? max(left, right) + 1 : 0;
    }
 
public:
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        // Start DFS with dummy parent value greater than node.val range
        dfs(root, 1001); 
        return res;
    }
};