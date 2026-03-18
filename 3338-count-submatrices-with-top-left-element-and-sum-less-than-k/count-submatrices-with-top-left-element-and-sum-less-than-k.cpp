class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> col(m);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int r = 0;
            for (int j = 0; j < m; j++) {
                col[j] += grid[i][j];
                r += col[j];
                if (r <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};