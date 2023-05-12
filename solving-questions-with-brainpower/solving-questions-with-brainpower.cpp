class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return funct(0, questions,dp);
    }

    long long funct(int idx,vector<vector<int>>& questions,vector<long long>& dp){
        if(idx >= questions.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long take_it = questions[idx][0] + funct(idx+questions[idx][1]+1, questions,dp);
        long long leave_it = funct(idx+1,questions,dp);

        return dp[idx] = max(take_it, leave_it);
    }
};