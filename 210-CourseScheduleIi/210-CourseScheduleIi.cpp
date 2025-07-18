// Last updated: 17/07/2025, 20:52:24
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        int inorder[numCourses] ;
        for(int i = 0;i<numCourses;i++){
            inorder[i] = 0;
        }
        for(int i = 0; i<numCourses;i++){
            for(auto it: adj[i]){
                inorder[it]++;
            }
        }
        // for(int i = 0;i<numCourses;i++){
        //     cout<<inorder[i]<<" ";
        // }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i< numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
                
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                    // ans.push_back(it);
                }
            }
            
        }
        if(ans.size()==numCourses)
        return ans;
        return {};

    }
};