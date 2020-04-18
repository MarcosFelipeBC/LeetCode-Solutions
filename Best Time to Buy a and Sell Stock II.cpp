class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        int buy = -1;
        for (int i=0; i<n; i++){
            if(buy == -1) buy = prices[i];
            else if(buy > prices[i]) buy = prices[i];
            else {
                ans += prices[i] - buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};