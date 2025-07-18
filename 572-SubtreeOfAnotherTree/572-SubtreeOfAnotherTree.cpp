// Last updated: 17/07/2025, 20:51:59
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            return false;
        }
        if(p == NULL && q == NULL){
            return true;
        }
        if(p->val != q->val){
            return false;
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        bool res = isSameTree(root,subRoot);
        if(res){
            return true;
        }
        return isSubtree(root->left , subRoot) || isSubtree(root->right, subRoot);
    }
};