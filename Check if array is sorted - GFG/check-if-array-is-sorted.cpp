//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n){
        int pre = arr[0];
        int cur;
        for(int i = 1; i < n; i++){
            cur = arr[i];
            if(pre <= cur){
                pre = cur;
            }
            else{
                return 0;
                break;
            }
        }
        return 1;
    }
    /*
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        int small = INT_MAX;
        int large = INT_MIN;
        for(int i = 0; i < n; i++){
            small = min(small,arr[i]);
            large = max(large, arr[i]);
        }
        if(small == arr[0] && large == arr[n-1]){
            return 1;
        }
        return 0;
    }
    */
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends