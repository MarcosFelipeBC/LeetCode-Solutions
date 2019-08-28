//https://leetcode.com/problems/increasing-subsequences/

class Solution {
public:

    void solve(int pos, vector < int >& aux, set < vector < int > > &s, vector < int >& vet){
        if(pos == vet.size()){
            if(aux.size() >= 2) s.insert(aux);
            return ;
        }
        solve(pos+1, aux, s, vet);
        if(aux.empty() || aux.back() <= vet[pos]){
            aux.push_back(vet[pos]);
            solve(pos+1, aux, s, vet);
            aux.pop_back();
        }
        return ;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <int > aux;
        vector< vector < int > > ans;
        set < vector< int > > s;
        solve(0, aux, s, nums);
        for (auto x : s) ans.push_back(x);
        return ans;
    }
};
