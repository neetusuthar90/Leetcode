class Solution {
public:
    int dp[102][102];
    int solve(vector<int>& cuts, int left, int right){
        if(right-left <= 1) return 0;

        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int cost = INT_MAX;
        for(int i = left+1; i <= right-1; i++){
            int leftCost = solve(cuts, left, i);
            int rightCost = solve(cuts, i, right);
            int curr_cost = (cuts[right]-cuts[left]) + leftCost + rightCost;
            cost = min(cost, curr_cost);
        }
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // 0 -> start of the stick
        // n -> end of the stick
        // 0 -> start of the cut array
        // cuts.size()-1 -> end of the cut array
        return solve(cuts, 0, cuts.size()-1);
    }
};