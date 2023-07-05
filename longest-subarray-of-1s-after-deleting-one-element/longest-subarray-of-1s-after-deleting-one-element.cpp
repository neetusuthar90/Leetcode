// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> count;
//         for(int i = 0; i < n; i++){
//             if(nums[i]==0){
//                 count.push_back(i);
//             }
//         }
//         if(count.size()==0){
//             return n-1;
//         }
//         int ans = 0;
//         for(int i = 0; i<count.size(); i++){
//             int len = 0;
//             int idx = count[i];
//             for(int j = 0; j < n; j++){
//                 if(j != idx && len > 0 && nums[j]==0){
//                     len = 0;
//                 }
//                 if(nums[j]==1){
//                     len++;
//                 }
//                 ans = max(ans,len);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int x =0;
        for(auto it:nums){
            if(it == 0){
                x++;
            }
        }
        if(x == 0){
            return n-1;
        }
        int i = 0, j = 0;
        int Zeros = 0;
        int Ones = 0;
        int ans = 0;
        while(j < n){
            if(nums[j]==0){
                Zeros++;
            }
            if(nums[j]==1){
                Ones++;
            }
            if(Zeros == 1 || nums[j]==1){
                ans = max(ans,Ones);
            }

            else if(Zeros>1){
                while(nums[i] != 0){
                    Ones--;
                    i++;
                }
                Zeros--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
  