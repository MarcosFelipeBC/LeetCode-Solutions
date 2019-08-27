//https://leetcode.com/problems/combinations/

class Solution {
public:
    
    void solve(const int &n, const int &k, vector < int > &aux, vector < vector < int > >&ans){
        if(k == 0){
            ans.push_back(aux);
            return ;
        }
        if(n == 0) return ;
        solve(n-1, k, aux, ans);
        aux.push_back(n);
        solve(n-1, k-1, aux, ans);
        aux.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector < vector < int > > ans;
        vector < int > aux;
        solve(n, k, aux, ans);
        return ans;
    }
};
