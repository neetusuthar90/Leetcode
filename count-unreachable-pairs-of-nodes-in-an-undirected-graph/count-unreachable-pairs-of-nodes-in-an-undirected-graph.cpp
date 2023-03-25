class Solution {
public:
    void dfs(unordered_map<int,list<int>> &adj,vector<bool> &vis, long long &count, int node){
        vis[node] = true;
        count++;
        for(auto nbd:adj[node]){
            if(vis[nbd] == false){
                dfs(adj,vis,count,nbd);
            }
        } 
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);
        long long ans = ((long long) n*(n-1))/2;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                long long count = 0;
                dfs(adj,vis,count,i);
                ans -= count*(count-1)/2;
            }
        }
        return ans;
    }
};