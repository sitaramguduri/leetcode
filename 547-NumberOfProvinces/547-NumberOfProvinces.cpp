// Last updated: 17/07/2025, 20:52:00
class Solution {
public:
    void helper(vector<int>& vis, vector<vector<int>>& adj, int node){
        vis[node] = 1;
        for(auto i: adj[node]){
            if(!vis[i]){
                helper(vis, adj, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
         vector<vector<int>> adj(isConnected.size(), vector<int>(isConnected.size(), 0));
         for(int i = 0; i< isConnected.size(); i++){
            for(int j = 0; j< isConnected.size(); j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
         }
         vector<int> vis(isConnected.size(), 0);
         for(int i = 0; i< isConnected.size(); i++){
            if(!vis[i]){
                count++;
                helper(vis, adj, i);
            }
         }
         return count;
    }
};