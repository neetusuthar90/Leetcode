//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int canPlaceCows(vector<int> &stalls, int dist, int cows){
        int n = stalls.size();
        int cntCows = 1;
        int last = stalls[0];
        for(int i = 1; i < n; i++){
            if(stalls[i] - last >= dist){
                cntCows += 1;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int maxdist = stalls[n-1] - stalls[0];
        
        int low = 1, high = maxdist;
        while(low <= high){
            int mid = (low + high)/2;
            if(canPlaceCows(stalls,mid,k) == false){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends