class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =  nums.size();
        if(target > nums[n/2]){
            //right search
            for(int i = n/2+1; i < n; i++){
                if(target == nums[i]){
                    return i;
                }
            }
        }
        else if(target < nums[n/2]){
            //left search
            for(int i = 0; i < n/2; i++){
                if(target == nums[i]){
                    return i;
                }
            }
        }
        else if(target == nums[n/2]){
            return n/2;
        }
        return -1;
    }
};