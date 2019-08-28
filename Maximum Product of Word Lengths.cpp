//https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector < int > vet;
        for (string s : words){
            int x = 0;
            for (int i=0; i<s.size(); i++){
                x |= (1 << (s[i]-'a'));
            }
            vet.push_back(x);
        }
        int ans = 0;
        for (int i=0; i<(int)words.size()-1; i++){
            for (int j=i+1; j<(int)words.size(); j++){
                if((vet[i] & vet[j]) == 0)ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};
