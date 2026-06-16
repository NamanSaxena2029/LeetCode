class Solution {
public:
    string processStr(string s) {
        string s1 = "";
        for(int i = 0 ; i  < s.size() ; i++) {
            char ch = s[i];
            if(ch=='*')  {
                if(s1.size()!=0) {
                    s1.pop_back();
                }
            } else if (ch=='#') {
                s1 += s1;
            } else if (ch=='%') {
                reverse(s1.begin(),s1.end());
            } else {
                s1.push_back(ch);
            }
        }
        return s1;
    }
};