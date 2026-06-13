class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string s : words) {
            int sum = 0;
            for(char c : s) {
                sum += weights[c-'a'];
            }
            int x =sum%26;
            char z = 'z'-x;
            ans += z;
        }
        return ans;
    }
};