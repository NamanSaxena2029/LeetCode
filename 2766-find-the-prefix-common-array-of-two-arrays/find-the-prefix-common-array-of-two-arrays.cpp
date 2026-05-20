class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // unordered_map<int, int> mp;
        // int common  = 0;
        // vector<int> arr(A.size());
        // for(int i = 0 ; i < A.size() ; i++) {
        //     mp[A[i]]++;
        //     if(mp[A[i]]==2) {
        //         common++;
        //     }
        //     mp[B[i]]++;
        //     if(mp[B[i]]==2) {
        //         common++;
        //     }
        //     arr[i] = common;
        // }
        // return arr;

/* Frequency Array*/
        vector<int> freq(A.size()+1, 0);
        vector<int> arr(A.size());
        int common = 0;
        for(int i = 0 ; i < A.size() ; i++) {
            freq[A[i]]++;
            if(freq[A[i]]==2) {
                common++;
            }
            freq[B[i]]++;
            if(freq[B[i]]==2) {
                common++;
            }
            arr[i] = common;
        }
        return arr;
    }
};