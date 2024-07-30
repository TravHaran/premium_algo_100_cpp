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
        ImmutableListNode* cur = head;
        _print(cur);
        
    }
    void _print(ImmutableListNode* cur){
        if(!cur) return;
        _print(cur->getNext());
        cur->printValue();
        
    }
};