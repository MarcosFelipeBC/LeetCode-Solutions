//https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int n = N;
        int freq[10], qtd[10], total = 0;
        memset(freq, 0, sizeof freq);
        while (n > 0){
            total++;
            freq[n%10]++;
            n/=10;
        }
        for (int i=0; i<31; i++){
            int val = (1 << i);
            for (int j=0; j<10; j++) qtd[j] = freq[j];
            int soma = 0;
            while (val > 0){
                int x = val%10;
                if(qtd[x] > 0) qtd[x]--;
                else break;
                soma++;
                val /= 10;
            }
            if(val == 0 && soma == total) return true;
        }
        return false;
    }
};
