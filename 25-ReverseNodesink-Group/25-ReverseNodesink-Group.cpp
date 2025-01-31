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
        ListNode* reverse(ListNode* head) {
       if(head == nullptr || head->next == nullptr){
            return head;
       }
       ListNode* newHead = reverse(head->next);
       ListNode* front = head->next;
       front->next = head;
       head->next = nullptr;
       return newHead;
    }

    ListNode* findk(ListNode* head,int k){
        ListNode* temp = head;
        int count = 0;
        ListNode* result = NULL;
        while(temp!=NULL && count < k){
            result = temp;
            temp = temp->next;
            count++;
            
        }
        if(count == k)
        return result;
        return NULL;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while(temp!=NULL){
            ListNode* k_node = findk(temp,k);

            if(k_node!=NULL){
                nextNode = k_node->next;
                k_node->next = NULL;
            }else{
                prevNode->next = temp;
                break;
            }
            
            // prevNode = temp;
            ListNode* reverseHead = reverse(temp);
            if(head == temp){
                head = reverseHead;
            }
            if(prevNode)
            prevNode->next = reverseHead;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};