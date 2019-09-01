//https://leetcode.com/problems/diet-plan-performance/

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int sum = 0;
        int ans = 0;
        for (int i=0; i<k; i++){
            sum += calories[i];
        }
        if(sum > upper) ans++;
        if(sum < lower) ans--;
        for (int i=k; i<n; i++){
            sum -= calories[i-k];
            sum += calories[i];
            if(sum > upper) ans++;
            if(sum < lower) ans--;
        }
        return ans;
    }
};
