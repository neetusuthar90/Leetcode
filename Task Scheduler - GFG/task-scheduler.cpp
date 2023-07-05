//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int x = 0;
        int f = 0;
        
        unordered_map<char,int> mpp;
        for(auto c:tasks){
            mpp[c]++;
            if(f < mpp[c]){
                f = mpp[c];
            }
        }
        
        for(auto m:mpp){
            if(m.second == f){
                x++;
            }
        }
        
        return max((K+1)*(f-1)+x , N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends