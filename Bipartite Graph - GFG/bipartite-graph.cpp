//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, int c, vector<int> adj[], vector<int> &color){
        // Mark visited or color the node
        color[node] = c;
        
        for(auto it:adj[node]){
            if(color[it] == -1){
                if(dfs(it, !c, adj, color) == false){
                    return false;
                }
            }
            else if(color[it] == c){
                // Color of adj node is same
                return false;
            }
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1); //Just like visited array and keep track of color
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(dfs(i,0,adj,color) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends