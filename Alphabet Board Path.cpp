//https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int nowx = 0, nowy = 0;
        for (int i=0; i<(int)target.size(); i++){
            char c = target[i];
            int posx = (c-'a')%5, posy = (c-'a')/5;
            char add;
            if(c == 'z'){
                if(nowx < posx) add = 'R';
                else add = 'L';
                for (int j=0; j<abs(posx-nowx); j++) ans.push_back(add);
                if(nowy < posy) add = 'D';
                else add = 'U';
                for (int j=0; j<abs(posy-nowy); j++) ans.push_back(add);
            }
            else {
                if(nowy < posy) add = 'D';
                else add = 'U';
                for (int j=0; j<abs(posy-nowy); j++) ans.push_back(add);
                if(nowx < posx) add = 'R';
                else add = 'L';
                for (int j=0; j<abs(posx-nowx); j++) ans.push_back(add);
            }
            ans.push_back('!');
            nowx = posx, nowy = posy;
        }
        return ans;
    }
};
