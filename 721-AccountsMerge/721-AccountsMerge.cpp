// Last updated: 17/07/2025, 20:51:56
class Disjoint{
    vector<int> size,parent,rank;
    public:
    Disjoint(int n){
        size.resize(n+1);
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i =0;i<n+1;i++){
            parent[i] = i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        Disjoint ds(n);
        sort(accounts.begin(),accounts.end());
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }else{
                    // when the map already has the mail then use the union to merge the sets
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it:mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0 ; i< n ; i++){
            sort(mergedMail[i].begin(),mergedMail[i].end());
            if(mergedMail[i].size() == 0){
                continue;
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};