class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return LCS(nums1,nums2,n1,n2,dp);
    }

    int LCS(vector<int> &nums1, vector<int> &nums2,int n1, int n2, vector<vector<int>> &dp){
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        
        if(nums1[n1-1] == nums2[n2-1]){
            return dp[n1][n2] = 1 + LCS(nums1, nums2, n1-1, n2-1,dp);
        }

        else{
            return dp[n1][n2] = max(LCS(nums1, nums2, n1, n2-1,dp), LCS(nums1, nums2, n1-1, n2,dp));
        }
    }
};