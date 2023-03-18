class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            for(int j = 1; j!=i && j < N; j++){
                if(nums[i] + nums[j] == target){
                    arr.push_back(i);
                    arr.push_back(j);
                    break;
                }
                else{
                    continue;
                }
            }
        }
        return arr;
    }
};