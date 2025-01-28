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
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* first = head->next;
        first->next = head;
        head->next = nullptr;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= nullptr && fast->next->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* second = newHead;
        ListNode* first = head;
        while(second!=nullptr){
            if(second->val != first->val ){
                return false;
            }
            second = second->next;
            first = first->next;
        }
        return true;
    }
};