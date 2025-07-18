// Last updated: 17/07/2025, 20:51:47
class Solution {
public:
    bool eatInTime(int k, int h , vector<int> piles){
        long timeTaken = 0;
        for(int i = 0; i< piles.size(); i++){
            long temp = ceil(1.0 * piles[i] / k);
            // cout<<"temp: "<< temp<<endl;
            timeTaken += temp;
        }
        // cout<< "timeTaken: "<< timeTaken<< endl;
        if(timeTaken > h){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for(int i = 0; i< piles.size(); i++){
            r = max(r, piles[i]);
        }
        int m;
        int res = INT_MAX;
        while(l <= r){
            m = (l + r)/2;
            // cout << "m: "<< m<<endl;
            // cout<<"l: "<< l << " r: "<< r<< endl;
            if(eatInTime(m, h,piles)){
                r = m -1;
                res = min(res, m);
            }else{
                l = m+ 1;
            }
        }
        return res;
        
    }
};