/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        unordered_map<int, int> nodeValCount; //prev node to cur node
        ListNode* cur = head;
        while(cur){
            nodeValCount[cur->val]++;
            cur = cur->next;
        }
        cur = head;
        ListNode* prev = dummy;
        while(cur){
            if(nodeValCount[cur->val] > 1) prev->next = cur->next;
            else prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};