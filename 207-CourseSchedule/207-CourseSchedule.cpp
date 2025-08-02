// Last updated: 02/08/2025, 18:49:20
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        // int indegree[numCourses] = {0};
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0 ; i< numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() == numCourses){
            return true;
        }
        return false;

    }
};