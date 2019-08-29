//https://leetcode.com/problems/nth-magical-number/

class Solution {
public:
    
    static const int mod = 1000000007;
    
    int nthMagicalNumber(int N, int A, int B) {
        long long lo = 0, hi = 100000000000000LL, ans;
        long long mmc = ((A*B)/__gcd(A, B));
        while (lo <= hi){
            long long mid = (lo + hi) >> 1;
            long long qtd = mid/A + mid/B - mid/mmc;
            if(qtd >= N){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans%mod;
    }
    
};
