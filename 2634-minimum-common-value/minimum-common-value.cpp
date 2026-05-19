class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
/* Using 2 pointer */        
        // int i = 0 , j = 0;
        // while(i<nums1.size() && j<nums2.size()) {
        //     if(nums1[i]==nums2[j]) {
        //         return nums1[i];
        //     } else if (nums1[i] < nums2[j]) {
        //         i++;
        //     } else {
        //         j++;
        //     }
        // }
        // return -1;

/* Using set */
        unordered_set<int> mp;
        for(int i : nums1) {
            mp.insert(i);
        }
        for(int i : nums2) {
            if(mp.find(i) != mp.end()) {
                return i;
            }
        }
        return -1;
    }
};