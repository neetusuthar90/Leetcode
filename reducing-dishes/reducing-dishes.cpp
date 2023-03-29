class Solution {
public:
    vector<vector<int>> dp;
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        dp.resize(n, vector<int> (n+1,-1));
        return helper(0,1,arr);
    }

    int helper(int i, int t, vector<int> &arr){
        if(i >= arr.size()) return 0;
        if(dp[i][t] != -1) return dp[i][t];
        int not_include = helper(i+1,t,arr);
        int taken = arr[i]*t+ helper(i+1, t+1, arr);
        return dp[i][t] = max(not_include, taken);
    }
};