class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0 , t = 0, f = 0, maxi = 0;
        for(int j = 0 ; j < answerKey.size() ; j++) {
            if(answerKey[j]=='T') {
                t++;
            } else {
                f++;
            }
            while(min(t,f)>k) {
                if(answerKey[i]=='T') {
                    t--;
                } else {
                    f--;
                }
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};