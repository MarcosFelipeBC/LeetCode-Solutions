//https://leetcode.com/problems/can-make-palindrome-from-substring/

class Solution {
public:
    int qtd[30][100005];
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        memset(qtd, 0, sizeof qtd);
        for (int i=0; i<n; i++){
            qtd[s[i]-'a'][i]++;
            if(i) for (int j=0; j<26; j++)qtd[j][i] += qtd[j][i-1];
        }
        vector < bool > ans;
        for (int i=0; i<queries.size(); i++){
            int l = queries[i][0], r = queries[i][1], k = queries[i][2];
            int tam = r-l+1;
            int cont = 0;
            for (int j=0; j<26; j++){
                int amount = qtd[j][r];
                if(l-1 >= 0) amount -= qtd[j][l-1];
                if(amount & 1) cont++;
            }
            if(tam&1) cont--;
            if(cont/2 + cont%2 > k) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};
