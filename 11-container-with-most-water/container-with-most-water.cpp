class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxi = 0;
        while(i<j) {
            int w = j-i;
            int h = min(height[i],height[j]);
            maxi = max(maxi,w*h);
            if(height[i]<height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxi;
    }
};