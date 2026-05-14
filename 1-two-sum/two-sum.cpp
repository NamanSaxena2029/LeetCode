class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr.size() ; i++) {
            int oppo = target-arr[i];
            if(mp.find(oppo)!=mp.end()) {
                return {mp[oppo],i};
            }
            mp[arr[i]] = i;
        }
        return {};
    }
};