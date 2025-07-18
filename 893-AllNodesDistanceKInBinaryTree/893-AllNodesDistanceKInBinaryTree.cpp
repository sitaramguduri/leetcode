// Last updated: 17/07/2025, 20:51:48
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node ;
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        getParents(root, parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr = 0;
        // for(auto it: parent_track){
        //     cout<<it.first->val<<" "<<it.second->val;
        //     cout<<endl;
        // }
        // cout<<endl;
        while(!q.empty()){
            int size = q.size();
            if(curr == k){
                break;
            }
            curr++;
           
            for(int i =0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    visited[parent_track[node]] = true;
                    q.push(parent_track[node]);
                }
            }

        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};