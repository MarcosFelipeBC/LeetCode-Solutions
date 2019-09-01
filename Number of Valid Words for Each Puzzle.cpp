//https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

class Solution {
public:
    
    int solve(int pos, int mask, int first, int now, unordered_map < int, int >&mp){
        if(pos == 26){
            int ans = 0;
            ans += mp[now];
            return ans;
        }
        int ans = 0;
        if(pos != first) ans += solve(pos+1, mask, first, now, mp);
        if(mask & (1 << pos))  ans += solve(pos+1, mask, first, now | (1 << pos), mp);
        return ans;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map < int, int > mp;
        for (int i=0; i<words.size(); i++){
            int mask = 0;
            for (int j=0; j<words[i].size(); j++){
                int p = words[i][j] - 'a';
                mask |= (1 << p);
            }
            mp[mask]++;
        }
        vector < int > ans;
        for (int i=0; i<puzzles.size(); i++){
            int mask = 0;
            for (int j=0; j<puzzles[i].size(); j++){
                int p = puzzles[i][j] - 'a';
                mask |= (1 << p);
            }
            ans.push_back(solve(0, mask, puzzles[i][0]-'a', 0, mp));
        }
        return ans;
    }
};
