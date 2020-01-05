//https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int N) {
        int last = -1, tmp = 0, ans = 0;
        while (N > 0){
            if(last != -1){
                if(N%2 == 1){
                    ans = max(ans, tmp - last);   
                }
            }
            if(N%2 == 1) last = tmp;
            N /= 2;
            tmp++;
        }
        return ans;
    }
};
