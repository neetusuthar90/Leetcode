class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i = i+3){
            if(nums[i] != nums[i+1] || nums[i+1] != nums[i+2]){
                return nums[i];
            }

        }
        return nums[n-1];
    }
};