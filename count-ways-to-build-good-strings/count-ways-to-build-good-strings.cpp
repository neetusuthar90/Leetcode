class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1,-1);
        for(int i = low; i <= high; i++){
            ans = (ans + getCount(i,zero,one,dp)%mod)%mod;
        }
        return ans;
    }

    int getCount(int n, int zero, int one, vector<int> &dp){
        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 0;
        }

        if(dp[n] != -1) return dp[n];
        else{
            return dp[n] = getCount(n-zero, zero, one,dp)%mod + getCount(n-one, zero, one,dp)%mod;
        }
    }
};