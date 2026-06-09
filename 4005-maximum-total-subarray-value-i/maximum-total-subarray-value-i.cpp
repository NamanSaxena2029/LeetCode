class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = nums[0], mini = nums[0];
        for(int i = 0 ; i < nums.size(); i++) {
            if (nums[i]>maxi) {
                maxi = nums[i];
            }
            if (nums[i]<mini) {
                mini = nums[i];
            }
        }
        return 1LL*(maxi-mini)*k;
    }
};