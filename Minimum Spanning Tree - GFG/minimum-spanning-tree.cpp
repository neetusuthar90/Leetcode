//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        
        pq.push({0,0});
        int sum = 0;
        // O(E)
        while(!pq.empty()){
            //O(log E)
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node]==1) continue;
            //add it to mst
            vis[node] = 1;
            //If you need to find out MST then create a array and push here
            sum += wt;
            
            // O(E. log E)
            for(auto nbd:adj[node]){
                int adjNode = nbd[0];
                int edW = nbd[1];
                if(vis[adjNode]==0){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
    
    // Time complexity: O(E.log E)+ O(E.logE) = O(E.log E)
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends