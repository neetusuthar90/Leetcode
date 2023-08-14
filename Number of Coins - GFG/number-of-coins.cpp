//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int i, int coins[], int target, vector<vector<int>> &dp){
	    if(i == 0){
	        if(target%coins[0] == 0){
	            return target/coins[0];
	        }
	        return 1e9;
	    }
	    if(dp[i][target] != -1){
	        return dp[i][target];
	    }
	    int notake = solve(i-1,coins,target,dp);
	    int take = 1e9;
	    if(coins[i] <= target){
	        take = 1 + solve(i,coins,target-coins[i],dp);
	    }
	    
	    return dp[i][target] = min(notake, take);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    int ans = solve(M-1, coins,V,dp);
	    if(ans > V){
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends