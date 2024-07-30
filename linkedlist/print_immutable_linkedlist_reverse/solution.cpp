/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        vector<ImmutableListNode*> stack;
        ImmutableListNode* cur = head;
        while(cur){
            stack.push_back(cur);
            cur = cur->getNext();
        }
        while(!stack.empty()){
            stack.back()->printValue();
            stack.pop_back();
        }
    }
};