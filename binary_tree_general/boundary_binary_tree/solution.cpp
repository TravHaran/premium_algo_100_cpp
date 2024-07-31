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
    vector<int> boundary;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        boundary.push_back(root->val);
        if(isLeaf(root)) return boundary;
        addLeftBoundary(root->left);
        addLeafs(root);
        addRightBoundary(root->right);
        return boundary;
    }

    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }

    void addLeftBoundary(TreeNode* node){
        if(!node) return;
        if(!isLeaf(node)) boundary.push_back(node->val);
        if(node->left) addLeftBoundary(node->left);
        else addLeftBoundary(node->right);
    }

    void addLeafs(TreeNode* node){
        if(!node) return;
        if(isLeaf(node)) boundary.push_back(node->val);
        addLeafs(node->left);
        addLeafs(node->right);
    }

    void addRightBoundary(TreeNode* node){
        if(!node) return;
        if(node->right) addRightBoundary(node->right);
        else if(node->left) addRightBoundary(node->left);
        if(!isLeaf(node)) boundary.push_back(node->val);
    }
};