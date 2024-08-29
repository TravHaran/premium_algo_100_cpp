/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> graph;
    vector<int> result;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // traverse through tree build parent-child relationship
        // from target node do bfs for k steps
        // then append the nodes at the end of the traversal to the result
        buildGraph(root, nullptr);
        bfs(target, k);
        return result;
    }

    void buildGraph(TreeNode* node, TreeNode* parent){
        if(!node) return;
        if(parent) graph[node->val].push_back(parent);
        if(node->left) graph[node->val].push_back(node->left);
        if(node->right) graph[node->val].push_back(node->right);
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    void bfs(TreeNode* target, int k){
        unordered_set<int> visited;
        deque<pair<int, TreeNode*>> q;
        q.push_back({0, target});
        int count(0);
        while(!q.empty()){
            TreeNode* node = q.front().second;
            visited.insert(node->val);
            int steps = q.front().first;
            if(steps==k) result.push_back(node->val);
            q.pop_front();
            // traverse to parent and children from node
            for(auto& neighbor : graph[node->val]){
                if(!visited.count(neighbor->val) && steps < k) q.push_back({steps + 1, neighbor});
            }
        }
    }
};