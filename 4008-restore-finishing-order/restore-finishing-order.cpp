class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        unordered_set<int> mp;
        for(int i : friends) {
            mp.insert(i);
        }
        for(int i : order) {
            if(mp.find(i) != mp.end()) {
                res.push_back(i);
                mp.erase(i);
            }
        }
        return res;
    }
};