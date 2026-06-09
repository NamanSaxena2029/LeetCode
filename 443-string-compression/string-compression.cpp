class Solution {
public:
    int compress(vector<char>& chars) {
        int f = 0 ;
        for(int i = 0 ; i < chars.size() ;) {
            char curr = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i]==curr) {
                count++;
                i++;
            }
            chars[f++] = curr;
            if(count>1) {
                string s = to_string(count);
                for(char c : s) {
                    chars[f++] = c;
                }
            }
        }
        return f;
    }
};