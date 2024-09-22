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
    int bfs(TreeNode* node){
        deque<TreeNode*> q = {node};
        int sum = INT_MIN, cur_sum = 0, lvl = 0, max_lvl = -1;
        while(!q.empty()){
            cur_sum = 0;
            lvl++;
            for(int i = q.size(); i >0; i--){
                auto cur_node = q.front();
                cur_sum += cur_node->val;
                q.pop_front();
                if(cur_node->left) q.push_back(cur_node->left);
                if(cur_node->right) q.push_back(cur_node->right);
            }
            if(cur_sum > sum){
                sum = cur_sum;
                max_lvl = lvl;
            }
        }
        return max_lvl;
    }

public:
    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
};