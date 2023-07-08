class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<int> vec;
        for(int i = 0; i < n-1; i++){
            int sum = weights[i] + weights[i+1];
            vec.push_back(sum);
        }

        sort(vec.begin(), vec.end());
        long long maxi = 0, mini = 0;
        for(int i = 0; i < k-1; i++){
            maxi += vec[vec.size()-i-1];
            mini += vec[i];
        }

        return maxi-mini;
    }
};