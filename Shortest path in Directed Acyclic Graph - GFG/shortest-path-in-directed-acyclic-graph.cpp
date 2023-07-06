//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node, vector<int> &vis, vector<pair<int,int>> adj[], stack<int> &st){
        vis[node] = 1;
         
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first, vis, adj, st);
            }
        }
        st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int> vis(N,0);
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends