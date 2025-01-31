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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        //need to find the tail and the len of the linked list
        int len = 1;
        ListNode* tail = head;
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(tail->next!=NULL){
            tail = tail->next;
            len ++;
        }
        if(k%len == 0){
            return head;
        }
        tail->next = head;
        
        k = k%len;
        int shift = len - k;
        while(shift>1){
            shift--;
            temp = temp->next;
           
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};