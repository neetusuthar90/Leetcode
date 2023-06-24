class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        
        int totalSum = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char,int> mp;
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                totalSum += solve(mp);   
            }
        }

        return totalSum;
    }

    int solve(unordered_map<char,int> &mp){
        int maxi = -1;
        int mini = INT_MAX;

        for(auto it:mp){
            maxi = max(maxi, it.second);
            if(it.second >= 1){
                mini = min(mini, it.second);
            }
        }

        return maxi-mini;
    }
};