//https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    
    int dx[4], dy[4];
    
    bool check(int x, int y, const int &n, const int &m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int comp(int x, int y, vector<vector<int>> &vist, vector<vector<int>> &mat){
        vist[x][y] = 1;
        int ans = 1;
        for (int i=0; i<4; i++){
            int a = x+dx[i], b = y+dy[i];
            if(check(a, b, mat.size(), mat[0].size()) && mat[a][b] == 1 && vist[a][b] == 0){
                ans += comp(a, b, vist, mat);
            }
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        dx[0] = 0, dx[1] = 1, dx[2] = 0, dx[3] = -1;
        dy[0] = 1, dy[1] = 0, dy[2] = -1, dy[3] = 0;
        if(grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector < vector < int > > vist;
        vist.assign(n, vector < int >(m, 0));
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j] == 1) ans = max(ans, comp(i, j, vist, grid));
            }
        }
        return ans;
    }
};
