class Solution {
public:
    void dfs(unordered_map<int,list<int>> &adj,vector<int> &vis, int node){
        vis[node] = 1;
        for(auto nbd:adj[node]){
            if(vis[nbd] == 0){
                vis[nbd] = 1;
                dfs(adj,vis,nbd);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < (n-1)){
            return -1;
        }
        unordered_map<int,list<int>> adj;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int v = 0; v < n; v++){
            if(vis[v] == 0){
                dfs(adj,vis,v);
                count++;
            }
        }
        return count-1;
    }
};