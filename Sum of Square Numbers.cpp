//https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long int a=0; a*a<=c; a++){
            if(ceil(sqrt(c - a*a)) == (int)(sqrt(c - a*a))){
                return true;
            }
        }
        return false;
    }
};
