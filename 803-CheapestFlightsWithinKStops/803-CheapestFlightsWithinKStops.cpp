// Last updated: 17/07/2025, 20:51:49
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
           adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q; //stops,node,dis{0,{src,}}t
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto adjNode: adj[node]){
                int nextNode = adjNode.first;
                int cost = adjNode.second;
                if(cost+distance< dist[nextNode] && (stops)<=k ){
                    dist[nextNode] = cost+distance;
                    q.push({stops+1,{nextNode,cost+distance}});
                }
                
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};