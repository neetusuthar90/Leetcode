class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj,vector<int> &vis){
        int ans = 0;
        vis[node] = 1;
        for(auto nbd:adj[node]){
            if(!vis[abs(nbd)]){
                ans += dfs(abs(nbd),adj,vis)+(nbd>0);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<int> vis(n,0);
        int ans = dfs(0,adj,vis);
        return ans;
    }
};