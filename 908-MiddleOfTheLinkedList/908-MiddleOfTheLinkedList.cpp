// Last updated: 17/07/2025, 20:51:46
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // cout<<"slow: "<<
        while(fast!=nullptr && fast->next!= nullptr){
            // cout<<"fast: "<<fast->val<<" slow: "<<slow->val<<endl;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};