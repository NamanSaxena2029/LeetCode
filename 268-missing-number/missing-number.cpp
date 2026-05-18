class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mas = nums.size()*(nums.size()+1)/2;
        int mast = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            mast += nums[i];
        }
        return mas-mast;
    }
};