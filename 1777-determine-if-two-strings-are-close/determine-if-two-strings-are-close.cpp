class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        vector<int> mp(26,0), st(26,0);
        for(char c : word1) {
            mp[c-'a']++;
        }
        for(char c : word2) {
            st[c-'a']++;
        }
        for(int i = 0 ;  i < 26 ; i++) {
            if((mp[i]==0 && st[i]!=0) || mp[i]!=0 && st[i]==0) {
                return false;
            } 
        }
        sort(mp.begin(),mp.end());
        sort(st.begin(),st.end());
        return mp==st;
    }
};