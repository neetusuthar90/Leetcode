//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>> adj[n+1];
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        queue<pair<int,int>> q;
        q.push({0,k});
        
        vector<int> dist(n+1, 1e9);
        //dist[0] = 0;
        dist[k] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int node = it.second;
            
            for(auto nbr:adj[node]){
                int adjnode = nbr.first;
                int edgewt = nbr.second;
                
                if(edgewt+dis < dist[adjnode]){
                    dist[adjnode] = edgewt + dis;
                    q.push({edgewt+dis, adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i]==1e9){
                return -1;
            }else{
                ans = max(ans,dist[i]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends