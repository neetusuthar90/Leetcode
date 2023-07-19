//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void findPathHelper(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string temp,
            vector<vector<int>> &vis){
            
        if(i == n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }    
            
        //downwards : j fixed and i increasing i+1 since i start from 0
        if(i+1 < n && !vis[i+1][j] && mat[i+1][j] == 1){
            vis[i][j] = 1;
            findPathHelper(i+1,j,mat,n,ans,temp+'D',vis);
            vis[i][j] = 0;
        }
            
        //leftwards : i fixed and j decreasing
        if(j-1 >= 0 && !vis[i][j-1] && mat[i][j-1] == 1){
            vis[i][j] = 1;
            findPathHelper(i,j-1,mat,n,ans,temp+'L',vis);
            vis[i][j] = 0;
        }
            
        //rightward: i fixed and j increasing
        if(j+1 < n && !vis[i][j+1] && mat[i][j+1] == 1){
            vis[i][j] = 1;
            findPathHelper(i,j+1,mat,n,ans,temp+'R',vis);
            vis[i][j] = 0;
        }
            
        //upwards: j fixed and i decreasing
        if(i-1 >= 0 && !vis[i-1][j] && mat[i-1][j] == 1){
            vis[i][j] = 1;
            findPathHelper(i-1,j,mat,n,ans,temp+'U',vis);
            vis[i][j] = 0;
        }   
        return;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        
        if(m[0][0] == 1){
            findPathHelper(0,0,m,n,ans,"",vis);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends