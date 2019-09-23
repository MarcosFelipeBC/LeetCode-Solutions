//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int now = 0;
        int n = (int)prices.size();
        for (int i=0; i<n-1; i++){
            if(now){
                while (i+1 < n-1 && prices[i+1] >= prices[i]){
                    i++;
                }
                if(prices[i+1] < prices[i]){
                    ans += prices[i];
                    now = 0;
                }
            }
            if(!now){
                if(prices[i+1] > prices[i]){
                    ans -= prices[i];
                    now = 1;
                }
            }
        }
        if(now){
            ans += prices[n-1];
        }
        return ans;
    }
};
