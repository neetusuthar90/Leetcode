class Solution {
public:
    int dp[101][101];
    int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right){
        if(left > right) return 0;

        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int cost = INT_MAX;
        for(int i = left; i <= right; i++){
            int leftCost = solve(start_stick, cuts[i], cuts, left, i-1);
            int rightCost = solve(cuts[i], end_stick, cuts, i+1, right);
            int curr_cost = (end_stick - start_stick) + leftCost + rightCost;
            cost = min(cost, curr_cost);
        }
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        // 0 -> start of the stick
        // n -> end of the stick
        // 0 -> start of the cut array
        // cuts.size()-1 -> end of the cut array
        memset(dp, -1, sizeof(dp));
        return solve(0,n,cuts, 0, cuts.size()-1);
    }
};