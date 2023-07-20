//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs2(int node, vector<vector<int>>&newAdj, vector<int> &vis){
        vis[node] = 1;
        
        for(auto it:newAdj[node]){
            if(!vis[it]){
                dfs2(it,newAdj,vis);
            }
        }
        
    }
    
    void dfs(int node, vector<vector<int>>&adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        
        st.push(node);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        //reverse all the direction
        vector<vector<int>> newAdj(V);
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                newAdj[it].push_back(i);
            }
        }
        
        int noOfscc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                noOfscc++;
                dfs2(node,newAdj,vis);
            }
        }
        return noOfscc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends