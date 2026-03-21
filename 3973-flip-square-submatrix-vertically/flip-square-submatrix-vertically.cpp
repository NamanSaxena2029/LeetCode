class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int a = x;
        int b = x + k - 1;
        while (a < b) {
            for (int i = y; i < y + k; i++) {
                swap(grid[a][i], grid[b][i]);
            }
            a++;
            b--;
        }
        return grid;
    }
};