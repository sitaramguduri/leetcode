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
        if(head == nullptr){
            return NULL;
        }
        if(head->next == nullptr){
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