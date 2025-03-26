// Last updated: 26/03/2025, 17:22:34
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
    // ListNode* helper(ListNode* cur, ListNode* nex){
        
    //     if(cur == NULL ){
    //         return cur;
    //     }
    //     if(nex==NULL ){
    //         return cur;
    //     }
    //     ListNode* head = helper(nex->next,nex->next->next);
    //     nex->next = cur;
    //     cur->next = head;
    //     return nex;
    // }
    ListNode* h(ListNode* cur){
        if(cur == NULL){
            return cur;
        }
        if(cur->next == NULL){
            return cur;
        }
        ListNode* head = h(cur->next->next);
        ListNode* nex = cur->next;
        nex->next = cur;
        cur->next = head;
        return nex;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL ){
            return head;
        }
        ListNode* nex = head->next;
        // ListNode* res = helper(head,nex);
        ListNode* res = h(head);
        return res;
    }
};