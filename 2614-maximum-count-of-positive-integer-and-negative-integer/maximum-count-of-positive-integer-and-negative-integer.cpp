class Solution {
public:
    int lastNegative(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < 0) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
    int firstPositive(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > 0) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negative = lastNegative(nums)+1;
        int positive = n-firstPositive(nums);
        return max(negative, positive);
    }
};