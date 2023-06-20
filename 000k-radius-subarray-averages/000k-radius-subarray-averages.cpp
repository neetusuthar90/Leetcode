class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0){
            return nums;
        }
        vector<int> ans(n,-1);
        if(n <= k){
            return ans;
        }
        int i = 0, j = 0;
        int temp = k;
        long sum = 0;
        cout << n;
        while(j < n && temp < n-k){
            sum += nums[j];
            while(j-i+1 > (2*k+1)){
                sum -= nums[i];
                i++;
            }
            if(j-i+1 == (2*k+1)){
                ans[temp] = sum/(2*k+1);
                temp++;
            }
            j++;
        }

        return ans;
    }
};