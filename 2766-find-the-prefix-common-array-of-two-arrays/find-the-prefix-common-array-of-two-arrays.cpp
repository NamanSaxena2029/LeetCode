class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        int common  = 0;
        vector<int> arr(A.size());
        for(int i = 0 ; i < A.size() ; i++) {
            mp[A[i]]++;
            if(mp[A[i]]==2) {
                common++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2) {
                common++;
            }
            arr[i] = common;
        }
        return arr;
    }
};