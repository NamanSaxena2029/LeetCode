class Solution {
public:
    static const int LOG = 17;
    static const int MOD = 1e9 + 7;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    void dfs(int node, int parent) {
        up[node][0] = parent;
        for(int i = 1; i < LOG; i++) {
            if(up[node][i-1] != -1) {
                up[node][i] = up[up[node][i-1]][i-1];
            }
            else {
                up[node][i] = -1;
            }
        }
        for(int nei : adj[node]) {
            if(nei == parent) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }
    }
    int lca(int u, int v) {
        if(depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int i = LOG - 1; i >= 0; i--) {
            if((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        if(u == v) return u;
        for(int i = LOG - 1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    long long modPow(long long a, long long b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        adj.resize(n + 1);
        depth.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, -1));
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        vector<int> ans;
        for(auto &q : queries) {
            int u = q[0];
            int v = q[1];
            int ancestor = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[ancestor];
            if(dist == 0) {
                ans.push_back(0);
            }
            else {
                ans.push_back(modPow(2, dist - 1));
            }
        }
        return ans;
    }
};