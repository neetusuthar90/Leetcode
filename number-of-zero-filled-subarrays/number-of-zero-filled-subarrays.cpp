class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long totalCount = 0;
        long long m = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]==0){
                m++;
            }
            else{
                totalCount += m*(m+1)/2;
                m = 0;
            }
        }
        if(m > 0){
            totalCount += m*(m+1)/2;
        }
        return totalCount;
    }
};