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
    * each node in the tree has children
    * the root node is a node that is not the child of anyone
    * so how do find it
    * we can create a map of child and parent relationships
    * the key will be the child and the value will be the parent
    */
public:
    Node* findRoot(vector<Node*> tree) {
        Node* root = nullptr;
        unordered_map<Node*, Node*> parents;
        for(auto& n : tree){
            for(auto& c : n->children){
                // map the child to its parent
                parents[c] = n;
            }
        }
        // the root node won't have a parent so it wont be in the map
        for(auto& el : tree){
            if(!parents.count(el)){
                root = el;
                return root;
            }
        }
        return root;
        
    }
};