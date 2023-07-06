//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,int> Pair;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(n+1,1e9), parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push({0,1});
        
        dist[1] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                
                if(dist[adjnode] > dis + edgewt){
                    dist[adjnode] = dis + edgewt;
                    pq.push({dist[adjnode], adjnode});
                    
                    parent[adjnode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9){
            return {-1};
        }
        
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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