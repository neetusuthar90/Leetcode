class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int m = s.length();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][m];
    }

};