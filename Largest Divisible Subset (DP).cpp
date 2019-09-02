//https://leetcode.com/problems/largest-divisible-subset/submissions/

class Solution {
public:
    
    static const int N = 1005;
    int dp[N], last[N];
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector < int > ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp[0] = 1;
        last[0] = -1;
        int best = 0;
        for (int i=1; i<n; i++){
            dp[i] = 1;
            last[i] = -1;
            for (int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        last[i] = j;
                    }
                }
            }
            if(dp[best] < dp[i]) best = i;
        }
        while (best != -1){
            ans.push_back(nums[best]);
            best = last[best];
        }
        return ans;
    }
};
