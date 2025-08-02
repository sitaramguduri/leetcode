// Last updated: 02/08/2025, 18:48:47
class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit){
        if(visit[node]){
            return true;
        }
        visit[node] = true;
        for(auto& neighbor: adj[node]){
            if(neighbor == parent){
                continue;
            }
            if(dfs(neighbor,node,adj, visit)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // find the nodes
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            vector<bool> visit(n+1,false);
            if(dfs(edge[0],-1,adj,visit)){
                return {edge[0],edge[1]};
            }
        }
        return {};

    }
};