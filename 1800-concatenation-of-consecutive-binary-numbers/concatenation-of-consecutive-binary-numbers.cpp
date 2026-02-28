class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bitLength = 0;
        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0) {
                bitLength++;
            }
            long long power = 1;
            for(int j = 0; j < bitLength; j++) {
                power = (power * 2) % MOD;
            }
            result = (result * power) % MOD;
            result = (result + i) % MOD;
        }
        return result;
    }
};