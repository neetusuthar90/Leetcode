//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// BFS 
class Solution {
  public:
    void bfs(int x, int y, vector<vector<int>> &grid , vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1; 
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
            
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == 1){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            
        }
        
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                bfs(0,j,grid,vis);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                bfs(n-1,j,grid,vis);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                bfs(i,0,grid,vis);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                bfs(i,m-1,grid,vis);
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        
        return count;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends