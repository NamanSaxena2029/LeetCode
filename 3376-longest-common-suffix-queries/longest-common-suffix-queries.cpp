class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        struct TrieNode {
            int child[26];
            int idx, len;
            TrieNode() {
                memset(child, -1, sizeof(child));
                idx = -1;
                len = INT_MAX;
            }
        };
        vector<TrieNode> trie(1);
        for(int i = 0; i < wordsContainer.size(); i++) {
            string &word = wordsContainer[i];
            int n = word.size();
            if(n < trie[0].len || 
              (n == trie[0].len && i < trie[0].idx)) {
                trie[0].len = n;
                trie[0].idx = i;
            }
            int node = 0;
            for(int j = n - 1; j >= 0; j--) {
                int c = word[j] - 'a';
                if(trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(TrieNode());
                }
                node = trie[node].child[c];
                if(n < trie[node].len || 
                  (n == trie[node].len && i < trie[node].idx)) {
                    trie[node].len = n;
                    trie[node].idx = i;
                }
            }
        }
        vector<int> ans;
        for(string &query : wordsQuery) {
            int node = 0;
            for(int i = query.size() - 1; i >= 0; i--) {
                int c = query[i] - 'a';
                if(trie[node].child[c] == -1)
                    break;
                node = trie[node].child[c];
            }
            ans.push_back(trie[node].idx);
        }
        return ans;
    }
};