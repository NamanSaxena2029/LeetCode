class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        for(int i : s) {
            mp[i]++;
        }
        int vowel = 0, consonant = 0;
        for(auto i : mp) {
            char c= i.first;
            int count = i.second;
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                vowel = max(vowel,count);
            } else {
                consonant = max(consonant,count);
            }
        }
        return consonant+vowel;
    }
};