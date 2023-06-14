//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long GCD(long long A, long long B){
        long long rem = 0;
        while(B != 0){
            rem = A%B;
            A = B;
            B = rem;
        }
        
        return A;
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> res(2);
        res[1] = GCD(A,B);
        res[0] = (A*B)/res[1];
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends