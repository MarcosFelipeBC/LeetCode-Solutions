//https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector < int > ans;
        int sum = 0;
        for (int x : A) if(!(x & 1)) sum += x;
        for (int i=0; i<queries.size(); i++){
            int val = queries[i][0], idx = queries[i][1];
            if(!(A[idx] & 1)) sum -= A[idx];
            A[idx] += val;
            if(!(A[idx] & 1)) sum += A[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};
