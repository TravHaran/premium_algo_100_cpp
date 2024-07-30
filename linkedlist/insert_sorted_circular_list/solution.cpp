/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        //handle empty list
        if(!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        //handle single node list
        if(!head->next){
            if(head->val < insertVal) head->next = new Node(insertVal);
            else {
                Node* temp = new Node(insertVal, head);
                head = temp;
            }
            return head;
        }
        // handle multi-node list
        Node *cur = head, *prev = cur;
        Node *minPrev, *minNode, *maxNext, *maxNode;
        minPrev = minNode = maxNext = maxNode = nullptr;
        int minVal = INT_MAX, maxVal = INT_MIN, count(0);
        while((count<=2) && cur){
            if(prev == head) count++;
            prev = cur;
            cur = cur->next;
            if(cur->val < minVal){
                minVal = cur->val;
                minNode = cur;
                minPrev = prev;
            }
            if(cur->val > maxVal){
                maxVal = cur->val;
                maxNode = cur;
                maxNext = cur->next;
            }
            if(prev->val <= insertVal && insertVal <= cur->val){
                prev->next = new Node(insertVal);
                prev->next->next = cur;
                return head;
            }
        }
        // insert beginning or end
        if(head->val < insertVal){
            // all nodes are less than the value
            minPrev->next = new Node(insertVal);
            minPrev->next->next = minNode;
        } else {
            // all nodes are greater than the value
            maxNode->next = new Node(insertVal);
            maxNode->next->next = maxNext;
        }
        return head;
    }
};