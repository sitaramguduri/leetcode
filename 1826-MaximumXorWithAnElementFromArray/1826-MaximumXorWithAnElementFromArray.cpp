// Last updated: 02/08/2025, 18:48:26
struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{

    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = num >>i & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i>= 0; i--){
            int bit = num >>i & 1;
            if(node->containsKey(1-bit)){
               maxNum = maxNum | 1 <<i;
               node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
}; //
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        int q = queries.size();
        for(int i = 0; i<q;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oQ.begin(),oQ.end());
        int ind= 0;
        int n = nums.size();
        vector<int> ans(q, -1);
        Trie trie;
        for(int i = 0; i<q; i++){
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;
            while(ind < n && nums[ind] <= mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0){
                ans[qInd]= -1;
            }else{
                ans[qInd] = trie.getMax(xi);
            }
        }
        return ans;
    }
};