class Solution {
public:
    int atmostK(vector<int>& arr, int k){
        int i = 0, j=0;
        unordered_map<int,int> mp;
        int count = 0;

        while(j<arr.size()){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int first_count = atmostK(nums, k);  //Atmost k
        int second_count = atmostK(nums, k-1); //Atmost k-1
        
        //Exactly k = atmost(k) - atmost(k-1);
        int ans = first_count - second_count;
        return ans;
    }
};