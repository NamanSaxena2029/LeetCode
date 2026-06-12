class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, count = 0;
        for(int j = 0 ; j < nums.size(); j++) {
            if(nums[j]==0) {
                count++;
            }
            if(count>k) {
                if(nums[i]==0) {
                    count--;
                }
                i++;
            }
        }
        return nums.size()-i;
    }
};