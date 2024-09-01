/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
    /*
    * similar appraoch to clone graph problem (lc 133)
    * recursive post order dfs of tree
    */
public:
    Node* cloneTree(Node* root) {
        if(!root) return nullptr;
        Node* root_clone = new Node(root->val);
        for(auto& child : root->children){
            Node* child_clone = cloneTree(child);
            root_clone->children.push_back(child_clone);
        }
        return root_clone;
    }
};