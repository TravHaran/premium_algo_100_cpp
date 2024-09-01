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
    * we add the value of each node to value_sum and we deduct the value of each child node from the value_sum.
    * At the end, the value_sum would be the value of the root node.
    * this can be done with the XOR operation: ^
    * For this idea to work, an important condition is that the values of all nodes are unique
    */
public:
    Node* findRoot(vector<Node*> tree) {
        int sum = 0;
        for(auto& n : tree){
            sum ^= n->val;
            for(auto& c : n->children){
                sum ^= c->val;
            }
        }
        for(auto& el : tree){
            if(el->val == sum) return el;
        }
        return nullptr;
    }
};