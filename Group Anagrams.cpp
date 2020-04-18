class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector < pair < string, string > > aux;
        for (string s : strs){
            aux.push_back({"", s});
            sort(s.begin(), s.end());
            aux.back().first = s;
        }
        sort(aux.begin(), aux.end());
        vector < vector < string > > ans;
        for (int i=0; i<strs.size(); i++){
            vector < string > v;
            int pos = i;
            v.push_back(aux[i].second);
            while (pos+1 < strs.size() && aux[pos].first == aux[pos+1].first){
                v.push_back(aux[pos+1].second);
                pos++;
            }
            i = pos;
            ans.push_back(v);
        }
        return ans;
    }
};
