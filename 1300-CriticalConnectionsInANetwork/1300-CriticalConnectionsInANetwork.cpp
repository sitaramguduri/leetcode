// Last updated: 17/07/2025, 20:51:38
class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent, vector<int>&vis,int tin[],int low[],vector<int> adj[],vector<vector<int>>& bridges){
        tin[node] = low[node] = timer;
        timer++;
        vis[node] = 1;
        for(auto it: adj[node]){
            if(it == parent){
                continue;
            }
            if(vis[it]==0){
                //call dfs on the unvisited nodes and then set the low array 
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    //this means that only way to get to the adjacent nodes is through crossing the node
                    //so it needs to be a bridge
                    bridges.push_back({it,node});
                }
            }else{
                low[node] = min(low[node],low[it]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tin[n];
        int low[n];
        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,vis, tin,low,adj,bridges);
        return bridges;
    }
};