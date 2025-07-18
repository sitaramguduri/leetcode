// Last updated: 17/07/2025, 20:51:58
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        vector<int> counts(26,0);
        for(char i: tasks){
            counts[i-'A']++;
        }
        for(int count: counts){
            if(count > 0){
                maxHeap.push(count);
            }
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
           
            time++;
            // cout<<"time: "<< time<<" maxHeap: "<< maxHeap.size()<<" queue: "<<q.front().second<<endl;
            
            if(maxHeap.empty()){
                // cout<<"here"<<endl;
                time = q.front().second;
            }else{
                int temp = maxHeap.top() - 1;
                maxHeap.pop();
            
                pair<int, int> nextTime = {temp, time + n};
                if(temp > 0){
                    q.push(nextTime);
                }
            }
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
            
        }
        return time;
    }
};