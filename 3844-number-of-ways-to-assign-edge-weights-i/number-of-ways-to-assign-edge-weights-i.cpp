class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;
        while(b > 0) {
            if(b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        int depth = -1;
        while(!q.empty()) {
            int size = q.size();
            depth++;
            while(size--) {
                int node = q.front();
                q.pop();
                for(int nei : adj[node]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }
        }
        return power(2, depth - 1);
    }
};