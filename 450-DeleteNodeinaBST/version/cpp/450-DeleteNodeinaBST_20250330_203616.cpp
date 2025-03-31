// Last updated: 30/03/2025, 20:36:16
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* node = root;
        while(node!=NULL){
            if(node->val > key){
                if(node->left != NULL && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }else{
                    node = node->left;
                }
            }else{
                if(node->right != NULL && node->right->val ==key){
                    node->right = helper(node->right);
                    break;
                }else{
                    node = node->right;
                }
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* node){
        if(node->left == NULL){
            return node->right;
        }
        if(node->right == NULL){
            return node->left;
        }
        TreeNode* rightSubTree = node->right;
        TreeNode* rightMostNode = findRightMost(node->left);
        rightMostNode->right = rightSubTree;
        return node->left;
    }
    TreeNode* findRightMost(TreeNode* node){
        if(node->right == NULL){
            return node;
        }
        return findRightMost(node->right);
    }
};