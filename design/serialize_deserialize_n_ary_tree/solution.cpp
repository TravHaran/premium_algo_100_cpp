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

class Codec {
private:
    void _serialize(Node* node, string& s){
        if(!node) return;
        s += to_string(node->val);
        if(!node->children.empty()){
            // if the node has children
            s += "(";
            for(auto& n : node->children){
                _serialize(n, s);
                s += ",";
            }
            s += ")";
        }
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res = "";
        _serialize(root, res);
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        vector<Node*> stack;
        Node* cur = nullptr;
        for(int i = 0; i < data.size(); i++){
            // if character is digit
            if(isdigit(data[i])){
                string num = "";
                while(isdigit(data[i])){
                    num += data[i];
                    i++;
                }
                i--;
                cur = new Node(stoi(num));
            } else if (data[i]=='('){
                stack.push_back(cur);
            } else if (data[i]==','){
                stack.back()->children.push_back(cur);
            } else {
                // if character is ')'
                cur = stack.back();
                stack.pop_back();
            }
        }
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));