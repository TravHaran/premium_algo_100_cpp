using namespace std;

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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* prev;
        while(cur){
            for(int i = 0; i < m; i++){
                if(!cur) return head;
                prev = cur;
                cur = cur->next;
            }
            for(int i = 0; i < n; i++){
                if(!cur) return head;
                // delete cur node
                cur = cur->next;
                prev->next = cur;
            }
        }
        return head;
    }
};