// Last updated: 04/04/2025, 01:42:26
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
    void helper(vector<int> & preorder, int ub, int & count, TreeNode* node){
        if(count >= preorder.size()){
            return;    
        }
        
        if(preorder[count] < node->val){
            TreeNode* left = new TreeNode(preorder[count]);
            node->left = left;
            count ++;
            helper(preorder, node->val,count, left);
        }
         if(count >= preorder.size()){
            return;    
        }
        if(preorder[count] > node->val && preorder[count] < ub){
            TreeNode* right = new TreeNode(preorder[count]);
            node->right = right;
            count++;
            helper(preorder, ub, count, right);
        }
        return ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub = INT_MAX;
        TreeNode* root = new TreeNode(preorder[0]);
        int count = 1;
        helper(preorder, ub , count, root);
        return root;
    }
};