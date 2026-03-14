class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        function<void(string)> backtrack = [&](string curr) {
            if(curr.length()==n) {
                ans.push_back(curr);
                return;
            }
            for(char s : {'a','b','c'}) {
                if(curr.empty() || curr.back()!=s) {
                    backtrack(curr+s);
                }
            }
        };
        backtrack("");
        if(k<=ans.size()) {
            return ans[k-1];
        }
        return "";
    }
};