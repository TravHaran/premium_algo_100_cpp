class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val){
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MaxStack {
    Node* head;
    Node* tail;
    map<int, vector<Node*>> m;
public:
    MaxStack() {
        head = new Node(-1);
        tail = new Node(-1);
        tail->prev = head;
        head->next = tail;
    }
    
    void push(int x) {
        // Create node
        Node* node = new Node(x);
        // update map
        m[x].push_back(node);
        // Add node to end of list
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
    
    int pop() {
        // get the element at the end of the list
        Node* node = tail->prev;
        // update map
        m[node->val].pop_back();
        if(m[node->val].empty()) m.erase(node->val);
        // remove the element
        node->prev->next = tail;
        tail->prev = node->prev;
        return node->val;
    }
    
    int top() {
        // get the element at the end of the list
        Node* node = tail->prev;
        return node->val;
    }
    
    int peekMax() {
        return m.rbegin()->first;;
    }
    
    int popMax() {
        // get max val
        int val = peekMax();
        Node* node = m[val].back();
        // update map
        m[val].pop_back();
        if(m[val].empty()) m.erase(val);
        // remove element
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */