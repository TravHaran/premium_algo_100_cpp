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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
private:
    TreeNode* _encode(Node* node){
        if(!node) return nullptr;
        TreeNode* bNode = new TreeNode(node->val);
        TreeNode* root = bNode;
        if(!node->children.empty()){ // node has children
            // start new level on left with 1st child
            root->left = _encode(node->children[0]); 
            bNode = bNode->left;
            // add remaining children to the right
            for(int i = 1; i < node->children.size(); i++){ 
                bNode->right = _encode(node->children[i]);
                bNode = bNode->right;
            }
        }
        return root;
    }

    Node* _decode(TreeNode* node){
        if(!node) return nullptr;
        Node* nNode = new Node(node->val);
        if(node->left){ // node has children
            node = node->left; // step left
            nNode->children.push_back(_decode(node)); // add first child
            node = node->right; // check right
            while(node){ // add remainging children
                nNode->children.push_back(_decode(node));
                node = node->right;
            }
        }
        return nNode;
    }

public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        return _encode(root);
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        return _decode(root);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));