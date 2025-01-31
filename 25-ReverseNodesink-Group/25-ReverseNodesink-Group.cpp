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
    ListNode* findK(ListNode* head, int k){
        int i = 1;
        ListNode* temp = head;
        while (temp && i < k) { 
            temp = temp->next;
            i++;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int val) {
         ListNode* temp = head;
        ListNode* prevNode = nullptr; // To track the previous segment
        ListNode* newHead = nullptr; // New head of the list
        while(temp!=NULL){
            ListNode* k = findK(temp,val);
            if (!k) {
                if (prevNode) prevNode->next = temp;
                break;
            }
               
                ListNode* nextNode = k->next;
                 k->next = NULL;
                 
            ListNode* reversedHead = reverse(temp);

            if (!newHead) newHead = reversedHead; // Set new head if it's the first reversal

            if (prevNode) prevNode->next = reversedHead; // Connect previous part to new reversed part

            prevNode = temp; // After reversing, temp becomes the last node of this segment
            temp = nextNode;
           
            
        }
        return newHead ? newHead : head;
    }
};