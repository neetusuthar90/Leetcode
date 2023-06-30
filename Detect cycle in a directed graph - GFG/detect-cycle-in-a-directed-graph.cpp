//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // DFS travesal only just here we have 2 visited aaray, if a node is visited
    // in both visited array means there exist a cycle
    //Note: You cannot check cycle using algo of undirected graph cycle detection
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
        
        //Mark node visited
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true){
                    return true;
                }
            }
            
            else if(pathVis[it] == 1){
                return true;
            }
        }
        
        //Mark PathNode unvisited again
        pathVis[node] = 0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends