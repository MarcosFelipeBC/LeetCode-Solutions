class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector < bool > ans;
        int sum = 0;
        for (int i=0; i<(int)A.size(); i++){
            sum *= 2;
            sum += A[i];
            sum %= 5;
            if(sum == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
