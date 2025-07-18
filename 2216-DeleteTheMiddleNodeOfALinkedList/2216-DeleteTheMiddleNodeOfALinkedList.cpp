// Last updated: 17/07/2025, 20:51:35
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        if(head->next == nullptr|| head == nullptr){
            // delete head;
            return NULL;
        }
        ListNode* fast = head->next->next;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow->next;
        slow->next = slow->next->next;
        delete prev;
        return head;
    }
};