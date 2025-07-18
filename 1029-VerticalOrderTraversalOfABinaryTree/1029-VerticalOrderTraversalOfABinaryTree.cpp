// Last updated: 17/07/2025, 20:51:43
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int horizontal = p.second.second;
            mp[vertical][horizontal].insert(node->val);
            if(node->left){
                q.push({node->left,{vertical-1,horizontal+1}});
            }
            if(node->right){
                q.push({node->right,{vertical+1,horizontal+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:mp){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};