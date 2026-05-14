class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int i = 0, maxi = 0;
        for(int j = 0 ; j < s.length() ; j++) {
            while(mp.find(s[j])!=mp.end()) {
                mp.erase(s[i]);
                i++;
            }
            mp.insert(s[j]);
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};