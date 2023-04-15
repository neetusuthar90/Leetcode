class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,k,piles,dp);
    }

    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        if(i==piles.size()||k==0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int res = solve(i+1,k,piles,dp);
        int cur = 0;
        for(int j = 0; j < piles[i].size() && j < k; j++){
            cur += piles[i][j];
            res = max(res, solve(i+1,k-(j+1),piles,dp)+cur);
        }
        dp[i][k] = res;
        return dp[i][k];
    }
};