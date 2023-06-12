class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0){
            return res;
        }
        int i = 0;
        while(i < nums.size()){
            int prev = nums[i];
            while(i+1 < nums.size() && nums[i+1] == nums[i]+1){
                i = i+1;
            }
            int next = nums[i];
            string str = "";
            if(prev == next){
                str = to_string(prev);
            }else{
                str = to_string(prev) + "->" + to_string(next);
            }
            res.push_back(str);
            i++;
        }
        return res;
    }
};