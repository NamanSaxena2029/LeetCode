class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;
        const int MOD = 12345;
        vector<int> flat(size);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flat[idx++] = grid[i][j];
            }
        }
        vector<int> prefix(size, 1), suffix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (1LL * prefix[i-1] * flat[i-1]) % MOD;
        }
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i+1] * flat[i+1]) % MOD;
        }
        vector<vector<int>> ans(n, vector<int>(m));
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (1LL * prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }
        return ans;
    }
};