//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int N, int k) {
        // code her
        vector<int> sum(N,0);
        int Sum = 0;
        
        for(int i = 0; i < N; i++){
            Sum += arr[i];
            sum[i] = Sum;
        }
        if(N == k){
            return Sum;
        }
        int score = 0;
        int ans = 0;
        for(int i = 0; i <= k; i++){
            int j = i + N - k -1;
            if(i == 0) ans = sum[j];
            ans = sum[j] - sum[i-1];
            
            score = max(score, Sum-ans);
        }
        return score;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends