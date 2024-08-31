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
    /*
    * for each node in tree1 check for the compliment in tree2
    *
    */
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        bool check = false;
        traverse_tree1(root1, root2, target, check);
        return check;
    }

    void traverse_tree1(TreeNode* root1, TreeNode* root2, int target, bool& check){
        if(!root1) return;
        int compliment = target - root1->val;
        if(find_compliment(root2, compliment)){
            check = true;
            return;
        }
        traverse_tree1(root1->left, root2, target, check);
        traverse_tree1(root1->right, root2, target, check);
    }

    bool find_compliment(TreeNode* root, int compliment){
        if(!root) return false;
        else if(root->val == compliment) return true;
        else if(root->val < compliment) return find_compliment(root->right, compliment);
        else return find_compliment(root->left, compliment);
    }
};