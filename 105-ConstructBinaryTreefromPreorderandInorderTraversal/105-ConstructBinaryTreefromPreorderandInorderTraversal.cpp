// Last updated: 24/03/2025, 18:01:40
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
    TreeNode* build(vector<int>& preorder, long long int preStart, long long int preEnd,
     vector<int>& inorder, long long int inStart, long long int inEnd, map<long long int,long long int>& mp){
        if(preStart>preEnd || inStart> inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        long long int inRoot = mp[preorder[preStart]];
        long long int inLeft = inRoot - inStart;
        root->left = build(preorder, preStart+1, preStart+inLeft, inorder, inStart, inRoot-1, mp);
        root->right = build(preorder,preStart+inLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<long long int,long long int> inMap;
        for(int i =0; i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = build(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};