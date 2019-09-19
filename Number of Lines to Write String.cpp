https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector < int > resp;
        int ans = 0, cnt = 0;
        for (int i=0; i<S.size(); i++){
            while (i != S.size() && cnt+widths[S[i]-'a'] <= 100){
                cnt += widths[S[i]-'a'];
                i++;
            }
            if(i != S.size()) {
                ans++;
                cnt = widths[S[i]-'a'];
            }
        }
        if(cnt != 0) ans++;
        resp.push_back(ans);
        resp.push_back(cnt);
        return resp;
    }
};
