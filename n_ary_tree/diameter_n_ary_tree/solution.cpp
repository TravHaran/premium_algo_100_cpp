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
    * convert tree to a Bi-directional graph
    * for each node have an adjacency list that contains the parent and the children
    * run bfs on each node in graph and return the max depth
    */
public:
    int depth = 0;
    int diameter(Node* root) {
        get_height(root);
        return depth;
    }

    int get_height(Node* node){
        if(!node) return 0;
        int sum = 0;
        int maxH1 = 0, maxH2 = 0;
        // recursively get height of all the childeren.
        for(auto& c : node->children){
            int cH = get_height(c);
            // calculate max two heights.
            if(cH >= maxH1){
                maxH2 = maxH1;
                maxH1 = cH;
            } else if (cH > maxH2 && cH < maxH1){
                maxH2 = cH;
            }
        }
        //sum of maxheights can be diameter of the N array tree.
        depth = max(depth, maxH1 + maxH2);
        // return height of the node.
        return maxH1+1;
    }
};