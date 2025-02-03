/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* addCopies(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        // Node* t1 = head;
        // while(t1!=NULL){
        //     cout<<t1->val<<" ";
        //     t1 = t1->next;
        // }
        return head;
    }
    Node* addRandom(Node* head){
        Node* temp = head;
        Node* copyNode = NULL;
        while(temp!=NULL){
            copyNode = temp->next;
            if(temp->random)
            copyNode->random = temp->random->next;
            else
            copyNode->random = nullptr;
            temp = temp->next->next;

        }
        return head;
    }
    Node* addNext(Node* head){
        Node* dNode = new Node(-1);
        Node* res = dNode;
        Node* temp = head;
        while(temp!= nullptr){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
        Node* addedCopies = addCopies(head);
        Node* addedRandomPointers = addRandom(addedCopies);
        Node* addedNextPointers = addNext(addedRandomPointers);
        return addedNextPointers;
    }
};