//https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j] == 0) continue ;
                ans += 4;
                if(j+1 < m && grid[i][j+1] == 1) ans--;
                if(j > 0 && grid[i][j-1] == 1) ans--;
                if(i+1 < n && grid[i+1][j] == 1) ans--;
                if(i > 0 && grid[i-1][j] == 1) ans--;
            }
        }
        return ans;
    }
};
