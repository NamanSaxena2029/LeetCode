class Solution {
public:
    bool can(long long T, vector<int>& w, int h){
        long long total = 0;
        for(long long x : w){
            long long k = (-1 + sqrt(1 + 8*T/x)) / 2;
            total += k;
            if(total >= h) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18, ans = r;

        while(l <= r){
            long long mid = (l + r) / 2;
            if(can(mid, workerTimes, mountainHeight)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};