// Last updated: 17/07/2025, 20:51:35
#define mod 1000000007
class Solution {
public:
    long long int helper(int x, long long int n){
        if(n==0){
            return (double) (1.0);
        }
        long long int half = helper(x,n/2);
        long long int ans = half* half;
        ans = ans%mod;
        return n%2==0?(ans)%mod:(ans*x)%mod;
    }

    int countGoodNumbers(long long n) {
        long long int res = 1;
        if( n%2 == 0){
            long long int half =(int)( helper(5,n/2))%mod;
            long long int odd = (int) helper(4,n/2)%mod;
            res = (half*odd)%mod;
        }else{
            long long int half =(int) helper(5,n/2 + 1);
            long long int odd = (int)helper(4,n/2);
            res = (half*odd)%mod;
        }
        return res;
    }
};