class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<tuple<int,int,int>> st;
        for(int i=0;i<n;i++) {
            int mx = nums[i];
            int l = i;
            int r = i;
            while(!st.empty() && get<0>(st.back()) > nums[i]) {
                mx = max(mx, get<0>(st.back()));
                l = get<1>(st.back());
                st.pop_back();
            }
            st.push_back({mx,l,r});
        }
        for(auto &[mx,l,r] : st) {
            for(int i=l;i<=r;i++) {
                ans[i] = mx;
            }
        }
        return ans;
    }
};