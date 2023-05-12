class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);
        
        for(int i = n-1; i >= 0; i--){
            int point = questions[i][0];
            int jump = questions[i][1];
            
            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], point+dp[nextQuestion]);
        }
        return dp[0];
    }

    long long funct(int idx,vector<vector<int>>& questions,vector<long long>& dp){
        if(idx >= questions.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long take_it = questions[idx][0] + funct(idx+questions[idx][1]+1, questions,dp);
        long long leave_it = funct(idx+1,questions,dp);

        return dp[idx] = max(take_it, leave_it);
    }
};