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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(-1);
        ListNode* oddTail = oddHead;
        ListNode* evenHead = new ListNode(-1);
        ListNode* evenTail = evenHead;
        ListNode* curr = head;
        int cnt = 1;
        while(curr!=NULL){
            ListNode* temp = curr;
            curr = curr->next;
            if(cnt%2 == 0){
                ListNode* even = new ListNode(temp->val);
                evenTail->next = even;
                evenTail = evenTail->next;
            }else{
                ListNode* even = new ListNode(temp->val);
                oddTail->next = even;
                oddTail = oddTail->next;
            }
            cnt++;
        }
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};