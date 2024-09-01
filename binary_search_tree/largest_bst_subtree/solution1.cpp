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
        int max_subtree = 0;
        dfs(root, max_subtree);
        return max_subtree;
    }

    void dfs(TreeNode* root, int& max_subtree){
        if(!root) return;
        int subtree_count = check_bst(root);
        max_subtree = max(max_subtree, subtree_count);
        dfs(root->left, max_subtree);
        dfs(root->right, max_subtree);
    }

    int check_bst(TreeNode* root){
        vector<TreeNode*> stack{root};
        TreeNode* prev = nullptr;
        TreeNode* node = root->left;
        int count = 0;
        while(node){
            stack.push_back(node);
            node = node->left;
        }
        while(!stack.empty()){
            node = stack.back();
            count++;
            stack.pop_back();
            if(prev && prev->val >= node->val) return -1;
            prev = node;
            node = node->right;
            while(node){
                stack.push_back(node);
                node = node->left;
            }
        }
        return count;
    }
};