class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
        }
        vector<int> ans(nums.size());
        int prefix = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            int suffix = sum - prefix - nums[i];
            ans[i] = abs(prefix-suffix);
            prefix += nums[i];
        }
        return ans;
    }
};