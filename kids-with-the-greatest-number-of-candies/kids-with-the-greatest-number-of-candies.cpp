class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(),candies.end());
        int n = candies.size();
        vector<bool> res(n,false);
        for(int i = 0; i < n; i++){
            int cur = candies[i]+extraCandies;
            if(cur >= mx){
                res[i] = true;
            }
        }
        return res;
    }
};