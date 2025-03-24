// Last updated: 24/03/2025, 18:21:34
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
    TreeNode* build(vector<int>& postorder, long long int postStart, long long int postEnd,
     vector<int> & inorder, long long int inStart, long long int inEnd, map<int, int>& mp){
        if(postStart> postEnd || inStart>inEnd){
            return NULL;
        }
        int inRoot = mp[postorder[postEnd]];
        int inRight = inEnd - inRoot;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        root->right = build(postorder, postEnd-inRight, postEnd-1, inorder, inRoot+1, inEnd,mp);
        root->left = build(postorder, postStart, postEnd-inRight-1, inorder, inStart, inRoot-1, mp);
        return root;
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i< inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};