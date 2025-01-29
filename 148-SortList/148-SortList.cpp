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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        while(left!=nullptr && right != nullptr){
            if(left->val < right->val){
                newHead->next = left;
                left = left->next;

            }else{
                newHead->next = right;
                right = right->next;
            }
            newHead = newHead->next;
        }
        while(left!=nullptr){
            newHead->next = left;
            left = left->next;
            newHead = newHead->next;
        }
        while(right!=nullptr){
            newHead->next = right;
            right = right->next;
            newHead = newHead->next;
        }
        return temp->next;

    }
    ListNode* findMiddle(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow= head;
        ListNode* fast = head->next;
        while( fast!=NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* left = head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};