class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();

        if(nums[0] != nums[1]){
            return nums[0];
        }else if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        int low = 1;
        int high = n-2;
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
            }

            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 &&                       nums[mid] == nums[mid+1])){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};