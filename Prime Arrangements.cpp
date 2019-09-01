//https://leetcode.com/problems/prime-arrangements/

class Solution {
public:
    
    bool prime(int x){
        for (int i=2; i*i<=x; i++){
            if(x%i == 0) return false;
        }
        return true;
    }
    
    int numPrimeArrangements(int n) {
        long long fat[110];
        fat[0] = 1;
        int primes=0;
        for (int i=1; i<=n; i++) fat[i] = (i*fat[i-1])%1000000007;
        for (int i=2; i<=n; i++){
            if(prime(i)){
                primes++;
            }
        }
        int resto = n-primes;
        return (fat[primes] * fat[resto])%1000000007;
    }
};
