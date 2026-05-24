class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> idx(n);
        for(int i = 0; i < n; i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(),
             [&](int a, int b) {
                 return arr[a] < arr[b];
             });
        for(int id : idx) {
            for(int j = id - 1;
                j >= max(0, id - d);
                j--) {
                if(arr[j] >= arr[id])
                    break;
                dp[id] = max(dp[id], 1 + dp[j]);
            }
            for(int j = id + 1;
                j <= min(n - 1, id + d);
                j++) {
                if(arr[j] >= arr[id])
                    break;
                dp[id] = max(dp[id], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};