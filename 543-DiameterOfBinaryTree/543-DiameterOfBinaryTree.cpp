// Last updated: 17/07/2025, 20:52:01
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
    int helper(TreeNode* root, int& res){
        
        if(root == NULL){
            return 0;
        }
        int lh = helper(root->left, res) ;
        int rh = helper(root->right, res);
        res = max(lh+rh,res);
        // cout<< max(lh, rh)<<" " << root->val<<endl;
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res  = 0;
        helper(root, res);
        return res;

    }
};