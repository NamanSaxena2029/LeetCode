class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int> rhombus;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rhombus.insert(grid[i][j]);
                for(int k = 1; i-k >= 0 && i+k < n && j-k >= 0 && j+k < m; k++){
                    int sum = 0;
                    for(int l = 0; l < k; l++)
                        sum += grid[i-k+l][j+l];
                    for(int l = 0; l < k; l++)
                        sum += grid[i+l][j+k-l];
                    for(int l = 0; l < k; l++)
                        sum += grid[i+k-l][j-l];
                    for(int l = 0; l < k; l++)
                        sum += grid[i-l][j-k+l];
                    rhombus.insert(sum);
                }
            }
        }
        vector<int> ans;
        for(int x : rhombus)
            ans.push_back(x);
        sort(ans.begin(), ans.end(), greater<int>());
        if(ans.size() > 3)
            ans.resize(3);
        return ans;
    }
};