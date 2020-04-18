class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long ans = -0x3f3f3f3f3f3f3f3f, sum = 0;
        for (int x : nums){
            sum += x;
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};