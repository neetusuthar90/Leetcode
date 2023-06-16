class Solution {
public:
    vector<vector<long long>> table;
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9+7;
        int n = nums.size();

        table.resize(n+1);
        for(int i = 0; i < n+1; i++){
            table[i] = vector<long long>(i+1,1);
            for(int j = 1; j < i; j++){
                table[i][j] = (table[i-1][j-1] + table[i-1][j])%mod;
            }
        }

        long long ans = dfs(nums,mod);
        return (ans%mod - 1)%mod;
    }

    long long dfs(vector<int>& nums, long long mod){
        int n = nums.size();
        if(n <= 2){
            return 1;
        }

        vector<int> left, right;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[0]){
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left,mod);
        long long rightWays = dfs(right,mod);

        int left_len = left.size(), right_len = right.size();

        return (((table[n-1][left_len] * leftWays)%mod)* rightWays)%mod;
    }
};