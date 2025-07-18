// Last updated: 17/07/2025, 20:51:45
class Solution {
public:
    int fib(int n) {
        if(n== 0 ){
            return 0;
        }
        if(n==1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};