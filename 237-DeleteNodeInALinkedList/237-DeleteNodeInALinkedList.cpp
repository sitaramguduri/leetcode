// Last updated: 17/07/2025, 20:52:16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
        return;
    }
};