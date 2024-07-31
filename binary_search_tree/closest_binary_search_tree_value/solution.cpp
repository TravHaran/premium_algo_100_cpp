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
    int closestValue(TreeNode* root, double target) {
        auto cur = root;
        double minDiff = DBL_MAX;
        int closestVal = INT_MAX;
        while(cur != nullptr){
            double diff = abs(cur->val - target);
            if((diff < minDiff) || (diff==minDiff)&&(cur->val < closestVal)){
                minDiff = diff;
                closestVal = cur->val;
            }
            if(target < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        return closestVal;
    }
};