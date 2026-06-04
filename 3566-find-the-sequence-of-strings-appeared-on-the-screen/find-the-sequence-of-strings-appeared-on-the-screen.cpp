class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string curr = "";
        for (char ch : target) {
            curr.push_back('a');
            while (curr.back() != ch) {
                ans.push_back(curr);
                curr.back()++;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};