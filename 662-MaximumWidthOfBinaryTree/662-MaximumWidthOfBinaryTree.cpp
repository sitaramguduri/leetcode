// Last updated: 17/07/2025, 20:51:56
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
 #include <deque>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //we will use a dequeue
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        deque<pair<TreeNode*, unsigned long long>> q;
        q.push_front({root, 0});
        while(!q.empty()){
            int size = q.size();
            unsigned long long first,second;
            unsigned long long mmin = q.back().second;
           
            for(int i =0; i<size;i++){
                TreeNode* node = q.back().first;
                unsigned long long val = q.back().second- mmin;
                 q.pop_back();
                if(i == 0){
                    first = val;
                }
                if(i == size-1){
                    second = val;
                }
                if(node->left){
                    q.push_front({node->left,(int)2*val+1});
                }
                if(node->right){
                    q.push_front({node->right, (int) 2*val+2});
                }
            }
            ans = max(ans,(int)(second-first+1));

        }
        return ans;
        
    }
};