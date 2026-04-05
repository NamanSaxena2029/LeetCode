class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, D = 0, L = 0, R = 0;
        for(char i : moves) {
            if(i == 'U') U++;
            else if(i == 'D') D++;
            else if(i == 'L') L++;
            else if(i == 'R') R++;
        }
        return (U == D && L == R);
    }
};