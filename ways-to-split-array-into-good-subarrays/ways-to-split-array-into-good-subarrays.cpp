class Solution {
    int mod = 1e9+7;
public:
    // Given an array [1 0 0 1] the split is equal to no. of zeros between two ones + 1
    // there for here total split equal to 4
    /// If array is like [1 0 0 1 0 1] then split is equal to 4 * (1+1) = 6
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();

        vector<int> vec;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                vec.push_back(i);
            }
        }
        if(vec.size() == 0){
            return 0;
        }

        long long ans = 1;
        for(int i = 0; i < vec.size()-1; i++){
            ans = ans*(vec[i+1]-vec[i]);
            ans = ans%mod;
        }

        return ans%mod;
    }
};