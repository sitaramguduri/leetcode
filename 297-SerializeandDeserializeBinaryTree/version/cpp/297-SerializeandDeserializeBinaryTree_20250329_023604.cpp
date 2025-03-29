// Last updated: 29/03/2025, 02:36:04
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<string>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while(!q.empty()){
            TreeNode* currentNode = q.front();
            q.pop();
            if(currentNode == NULL){
                s.append("#,");
            }else{
                s.append(to_string(currentNode->val) + ',');
            }
            if(currentNode != NULL){
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        queue<TreeNode*> q;
        string s;
        stringstream stream_string(data);
        getline(stream_string,s,',');
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);
        while(!q.empty()){
            TreeNode* currentNode = q.front();
            q.pop();
            getline(stream_string, s, ',');
            if( s == "#"){
                currentNode->left = NULL;
            }else{
                TreeNode* left = new TreeNode(stoi(s));
                currentNode->left = left;
                q.push(left);
            }

            getline(stream_string, s, ',');
            if( s == "#"){
                currentNode->right = NULL;
            }else{
                TreeNode* right= new TreeNode(stoi(s));
                currentNode->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));