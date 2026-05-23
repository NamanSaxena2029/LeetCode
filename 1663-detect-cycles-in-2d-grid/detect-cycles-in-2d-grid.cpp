class Solution {
public:
    int n, m;
    bool dfs(int row, int col,
             int parentRow, int parentCol,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if(grid[nr][nc] == grid[row][col]) {
                    if(!vis[nr][nc]) {
                        if(dfs(nr, nc, row, col, grid, vis))
                            return true;
                    }
                    else if(nr != parentRow || nc != parentCol) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
};