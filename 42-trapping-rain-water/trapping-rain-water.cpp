class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, left = 0, right = 0, total= 0;
        int j = height.size()-1;
        while(i<j) {
            left = max(left,height[i]);
            right = max(right,height[j]);
            if(left<right) {
                total += left - height[i];
                i++;
            } else {
                total += right - height[j];
                j--;
            }
        }
        return total;
    }
};