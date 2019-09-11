//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int Catch = nums[0], notCatch = 0;
        int n = nums.size();
        for (int i=1; i<n-1; i++){
            int auxC, auxnC;
            auxC = max(notCatch + nums[i], Catch);
            auxnC = max(notCatch, Catch);
            Catch = auxC, notCatch = auxnC;
        }
        int ans = max(Catch, notCatch);
        if(nums.size() == 1) return ans;
        Catch = nums[1], notCatch = 0;
        for (int i=2; i<n; i++){
            int auxC, auxnC;
            auxC = max(notCatch + nums[i], Catch);
            auxnC = max(notCatch, Catch);
            Catch = auxC, notCatch = auxnC;
        }
        ans = max(ans, max(Catch, notCatch));
        return ans;
    }
};
