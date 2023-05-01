class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int mx = *max_element(salary.begin(), salary.end());
        int mn = *min_element(salary.begin(), salary.end());
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += salary[i];
        }
        sum = sum - mx - mn;
        double ans = sum/(n-2);
        return ans;
    }
};