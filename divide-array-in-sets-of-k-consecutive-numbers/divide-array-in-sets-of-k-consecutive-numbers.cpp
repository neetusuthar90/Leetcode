class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 0){
                continue;
            }

            for(int j = 0; j < k; j++){
                int currNo = nums[i]+j;

                if(mp[currNo] == 0){
                    return false;
                }

                mp[currNo]--;
            }
        }

        return true;
    }
};