//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long sumOfSeries(long long N) {
        // code here
        long long ans = 0;
        helper(N, ans);
        return ans;
    }
    
    void helper(long long N, long long &ans){
        if(N == 0){
            return;
        }
        
        ans += N*N*N;
        helper(N-1,ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends