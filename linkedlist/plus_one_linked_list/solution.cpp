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
    ListNode* plusOne(ListNode* head) {
        // if the last digit is not 9 we can simply increment the value
        ListNode* cur = head;
        // find the lst node that's not nine
        ListNode* notNine = nullptr;
        while(cur->next){
            if(cur->val != 9) notNine = cur;
            cur = cur->next;
        }
        if(cur->val != 9) cur->val += 1;
        // else we need to increment the last node that wasn't nine
        else if(notNine){
            notNine->val += 1;
            while(notNine->next){
                notNine->next->val = 0;
                notNine = notNine->next;
            }
        } 
        // else all nodes are 9
        else {
            cur = head;
            cur->val = 1;
            while(cur->next){
                cur = cur->next;
                cur->val = 0;
            }
            cur->next = new ListNode(0);
        }
        return head;
    }
};