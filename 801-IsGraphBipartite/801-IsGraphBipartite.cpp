// Last updated: 22/07/2025, 13:53:09
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int col){
        color[node] = col;
        for(auto it: graph[node]){
            if(color[it] == -1){
                if(!dfs(graph, color, it, 1-col)){
                    return false;
                }
            }else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i<color.size(); i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i,0) ){
                    return false;
                }
            }

        }
        return true;

    }
};