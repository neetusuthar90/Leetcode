class Solution {
public:
    long long f(vector<int>& nums, vector<int>& cost, long long median){
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){
            ans += abs((1ll)*nums[i]-median)*(1ll*cost[i]);
        }

        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        vector<pair<int,int>> vec;

        for(int i = 0; i < nums.size(); i++){
            vec.push_back({nums[i],cost[i]});
        }

        sort(vec.begin(), vec.end());

        long long sum = 0;
        for(int i = 0; i < vec.size(); i++){
            sum += vec[i].second;
        }

        int i = 0;
        long long total = 0;
        long long median;
        while(total < (sum+1)/2 && i < nums.size()){
            total += vec[i].second;
            median = vec[i].first;
            i++;
        }

        return f(nums,cost,median);
    }
};