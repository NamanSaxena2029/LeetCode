class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> mp;
        for (int num : arr1) {
            string s = to_string(num);
            string pre = "";
            for (char ch : s) {
                pre += ch;
                mp.insert(pre);
            }
        }
        int ans = 0;
        for (int num : arr2) {
            string s = to_string(num);
            string fix = "";
            for (char ch : s) {
                fix += ch;
                if (mp.count(fix)) {
                    ans = max(ans, (int)fix.length());
                }
            }
        }
        return ans;
    }
};