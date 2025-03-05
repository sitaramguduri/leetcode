class Solution {
public:
    double helper(double x, long long int n){
        if(n==0){
            return (double) (1.0);
        }
        double half = helper(x,n/2);
        return n%2==0?half*half:half*half*x;
    }
    double myPow(double x, int n) {
        double res = 1;
        // long long int N = n;
        if(n>0){
            res = helper(x,(long long int) n);
        }else{
        //    x = 1.0/x;
           res = helper(x,-(long long int)n);
           res = 1/res;
        }
        return res;
    }
};