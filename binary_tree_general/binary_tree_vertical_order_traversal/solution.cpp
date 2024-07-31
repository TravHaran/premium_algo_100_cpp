#include <utility>
#include <deque>
#include <vector>
using namespace std;

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> table;
        deque<pair<TreeNode*, int>> q;
        q.push_back({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> el = q.front();
            q.pop_front();
            TreeNode* node = el.first;
            int column = el.second;
            if(node){
                table[column].push_back(node->val);
                q.push_back({node->left, column-1});
                q.push_back({node->right, column+1});
            }
        }
        vector<vector<int>> result;
        vector<int> keys;
        for(auto& [key, val] : table){
            keys.push_back(key);
        }
        sort(keys.begin(), keys.end());
        for(auto& k : keys){
            result.push_back(table[k]);
        }
        return result;
    }
};