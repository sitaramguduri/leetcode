class Solution {
public:
    double myPow(double x, int n) {
        int neg = 0;
        long long nn = n;
        if(n<0){
            nn = -1*nn;
            neg = 1;
        }
        double ans = 1;
        while(nn>0){
            if(nn%2 == 0 ){
                x = x * x;
                nn = nn/2;
            }else{
                ans = ans*x;
                nn = nn -1;
            }
        }
        if(neg == 1){
            ans = (double)1/(double)ans;
        }
        return ans;
    }
};