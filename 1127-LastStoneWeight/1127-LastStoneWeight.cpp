// Last updated: 17/07/2025, 20:51:40
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone: stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1){
            int heavy = maxHeap.top();
            maxHeap.pop();

            // if(maxHeap.size()!= 1)
            int second_heavy = maxHeap.top();
            maxHeap.pop();
            if(heavy > second_heavy){
                int dif = heavy - second_heavy;
                maxHeap.push(dif);
            }
        }
        if(maxHeap.size()==0){
            return 0;
        }
        return maxHeap.top();
    }
};