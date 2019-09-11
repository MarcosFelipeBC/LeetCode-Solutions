//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

class Solution {
public:
    
    static const int N = 1010;
    int dp[N][2];
    
    int solve(int pos, int changed, const vector < int > &A, const vector < int > &B){
        if(pos == A.size()) return 0;
        int &ans = dp[pos][changed];
        if(ans != -1) return ans;
        int lastA = A[pos-1], lastB = B[pos-1];
        if(changed) swap(lastA, lastB);
        ans = INT_MAX;
        if(A[pos] > lastA && B[pos] > lastB) ans = min(ans, solve(pos+1, 0, A, B));
        if(B[pos] > lastA && A[pos] > lastB) ans = min(ans, solve(pos+1, 1, A, B)+1);
        return ans;
    }
    
    int minSwap(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof dp);
        return min(solve(1, 0, A, B), solve(1, 1, A, B)+1);
    }
};
