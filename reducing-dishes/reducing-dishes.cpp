class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
       int n =  sat.size();
       sort(sat.begin(), sat.end());
       int max_sum = 0;
       int cum_sum = 0;
       int cur_sum = 0;
       for(int i = n-1; i >= 0; i--){
           cur_sum = cur_sum + cum_sum + sat[i];
           cum_sum = cum_sum + sat[i];
           max_sum = max(max_sum, cur_sum);
       }
       return max_sum;
    }
};