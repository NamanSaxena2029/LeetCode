class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> res(n, 0);
        for(auto &it : mp) {
            vector<int>& v = it.second;
            int m = v.size();
            long long total = 0;
            for(int x : v) total += x;
            long long leftSum = 0;
            for(int i = 0; i < m; i++) {
                long long idx = v[i];
                long long rightSum = total - leftSum - idx;
                long long leftCount = i;
                long long rightCount = m - i - 1;
                long long left = idx * leftCount - leftSum;
                long long right = rightSum - idx * rightCount;
                res[idx] = left + right;
                leftSum += idx;
            }
        }
        return res;
    }
};