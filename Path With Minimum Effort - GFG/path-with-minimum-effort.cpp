//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,pair<int,int>> triplet;
    
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<triplet, vector<triplet>, greater<triplet>> pq;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e6));
        dist[0][0] = 0;
        
        pq.push({0,{0,0}});
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            if(x == n-1 && y == m-1){
                return diff; 
            }
            
            for(int i = 0; i < 4; i++){
                int nx = x+ dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && ny >= 0 && nx < n && ny < m){
                    int newdiff = max(abs(heights[nx][ny] - heights[x][y]), diff);
                    
                    if(newdiff < dist[nx][ny]){
                        dist[nx][ny] = newdiff;
                        pq.push({newdiff, {nx,ny}});
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends