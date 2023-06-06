class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if(n == 2){
            return true;
        }
        sort(arr.begin(), arr.end());

        int d = arr[1]-arr[0];
        int ans;
        for(int i = 1; i < n-1; i++){
            int j = i+1;
            if(arr[i]+d == arr[j]){
                ans = true;
            }
            else{
                return false;
            }
        }
        return ans;
    }
};