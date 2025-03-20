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
    void recursiveTraversal(TreeNode* root, int level, map<int, int> & mp){
        if(root == NULL){
            return ;
        }
        if(mp.find(level) == mp.end()){
            mp[level] = root->val;
        }
        recursiveTraversal(root->right, level+1, mp);
        recursiveTraversal(root->left, level +1 , mp);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;
        recursiveTraversal(root, 0,mp);
        vector<int> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};