class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> mp(word.begin(), word.end());
        int count = 0;
        for(char i = 'a'; i <= 'z'; i++) {
            if(mp.count(i) && mp.count(i-'a'+'A')) {
                count++;
            }
        }
        return count;
    }
};