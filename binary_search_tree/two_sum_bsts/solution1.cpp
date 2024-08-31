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
    * go through bst1 and create a map of compliment to node values
    * go through bst2 and return true if compliment is found
    *
    */
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_map<int, int> tree1_compliments;
        build_compliments(tree1_compliments, root1, target);
        bool check = false;
        check_compliment(tree1_compliments, root2, check);
        return check;
    }

    void build_compliments(unordered_map<int, int>& map, TreeNode* root, int target){
        if(!root) return;
        map[target - root->val] = root->val;
        build_compliments(map, root->left, target);
        build_compliments(map, root->right, target);
    }

    void check_compliment(unordered_map<int, int>& map, TreeNode* root, bool& check){
        if(!root) return;
        if(map.count(root->val)){
            check=true;
            return;
        }
        check_compliment(map, root->left, check);
        check_compliment(map, root->right, check);
    }
};