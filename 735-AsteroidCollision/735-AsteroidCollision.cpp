// Last updated: 17/07/2025, 20:51:54
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            int val = asteroids[i];
            if(!s.empty() && s.top() >0 && val<0 ){
                if(abs(s.top()) == abs(val)){
                    s.pop();
                }else if(abs(val) > abs(s.top())){
                    s.pop();
                    i--;
                }
            }else{
                // cout<<"here"<<endl;
                s.push(val);
            }
        }
        vector<int> res(s.size(),0);
        for(int i = res.size()-1;i>=0;i--){
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};