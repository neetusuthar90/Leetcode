//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Shortest path means dijsktra algo using queue or priority queue but
// observing closely since it is a binary matrix or by dry running
// we can onserve that distances are increasing monotonically (because of constant edge weights). 
// Since greater distance comes at the top automatically, so we do not need the priority queue as 
// the pop operation will always pop the smaller distance which is at the front of the queue.

class Solution {
  public:
    typedef pair<int,pair<int,int>> triplet;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        
        queue<triplet> q;
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 1e9));
        
        dist[source.first][source.second] = 1;
        q.push({0,{source.first, source.second}});
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int weight = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx<grid.size() && ny<grid[0].size()
                                && grid[nx][ny] == 1 && weight+1 < dist[nx][ny]){
                    dist[nx][ny] = 1+weight;
                    
                    if(nx==destination.first && ny==destination.second){
                        return weight+1;
                    }
                    
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends