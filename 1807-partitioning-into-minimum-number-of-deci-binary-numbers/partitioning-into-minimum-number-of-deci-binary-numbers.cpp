class Solution {
public:
    int minPartitions(string n) {
        int a = 0;
        for(char c = 0 ; c < n.length() ; c++) {
            int digit = n[c]-'0';
            a = max(a,digit);
        }
        return a;
    }
};