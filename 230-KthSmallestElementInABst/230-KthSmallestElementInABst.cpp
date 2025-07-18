// Last updated: 17/07/2025, 20:52:18
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
    void f(TreeNode* root, int k, int & count, int & res){
        if(root == NULL){
            return ;
        }
        f(root->left, k, count,res);
       
        count++; 
        if(count == k){
            res = root->val;
        }
         f(root->right, k, count,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; 
        int res = 0;
        f(root, k, count,res);
        return res;
    }
};