class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for(int i = 0;i < n; i++){
            totalSum += cardPoints[i];
        }

        int window = n-k;
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MIN;

        while(j < n){
            sum += cardPoints[j];

            while(j-i+1 > window){
                sum -= cardPoints[i];
                i++;
            }

            if(j-i+1 == window){
                ans = max(ans, totalSum - sum);
            }

            j++;
        }

        return ans;
    }
};