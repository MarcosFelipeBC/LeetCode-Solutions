//https://leetcode.com/problems/target-sum/

class Solution {
public:
    
    int dp[21][2002];
    
    int solve(int pos, int sum, const long long &S, vector < int >&vet){
        if(pos == vet.size()) return (sum == S);
        int &ans = dp[pos][sum];
        if(ans != -1) return ans;
        return ans = solve(pos+1, sum+vet[pos], S, vet) + solve(pos+1, sum-vet[pos], S, vet);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp, -1, sizeof dp);
        return solve(0, 1000, (long long)S+1000LL, nums);
    }
};
