class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix = 0;
        int maxi = 0;
        for(int i = 0 ; i  < gain.size() ; i++) {
            prefix += gain[i];
            maxi = max(maxi,prefix);
        }
        return maxi;
    }
};