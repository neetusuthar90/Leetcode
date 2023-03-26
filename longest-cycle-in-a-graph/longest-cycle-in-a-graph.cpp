class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n,false);
        vector<bool> extra(n,false);
        vector<int> dist_node(n,0);
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,vis,extra,edges,dist_node,0,ans);
            }
        }
        return ans;
    }

    void dfs(int node, vector<bool> &vis, vector<bool> &extra, vector<int> &edges, vector<int> &dist_node, int distance, int &ans){
        if(node != -1){
            if(!vis[node]){
                vis[node] = true;
                extra[node] = true;
                dist_node[node] = distance;
                dfs(edges[node], vis,extra, edges, dist_node, distance+1,ans);
            }
            else if(extra[node]){
                ans = max(ans, distance-dist_node[node]);
            }
            extra[node] = false;
        }        
    }
};