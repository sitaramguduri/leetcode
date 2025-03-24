// Last updated: 24/03/2025, 17:56:47
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<long long int,long long int> mp;
        for( int i =0; i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder,long long int preStart,long long int preEnd,vector<int>&inorder,long long int inStart,long long int inEnd,map<long long int,long long int>& mp){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        long long int inRoot = mp[root->val];
        long long int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right = buildTree(preorder,preStart+1+numsLeft,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
};