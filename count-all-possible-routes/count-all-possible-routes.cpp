class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp){
        if(fuel < 0){
            return 0;
        }

        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }
        int ans = 0;
        if(start == finish){
            ans++;
        }

        for(int i = 0; i < locations.size(); i++){

            if(i == start || abs(locations[i]-locations[start]) > fuel){
                continue;
            }
            ans += solve(locations,i,finish, fuel-abs(locations[start]-locations[i]), dp);
            ans = ans%mod;
        }

        return dp[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int sz = locations.size();

        vector<vector<int>> dp(sz, vector<int> (fuel+1, -1));
        return solve(locations, start, finish, fuel, dp);
    }
};