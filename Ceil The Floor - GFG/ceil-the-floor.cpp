//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int v[], int n, int x) {
    // code here
    pair<int, int> ans;
    ans.first = -1;
    ans.second = -1;
    int low = INT_MIN;
    int high = INT_MAX;
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            ans.first = v[i];
            ans.second = v[i];
            break;
        }
        else if(v[i] < x){
            low = max(low,v[i]);
            ans.first = low;
            
        }
        else if(v[i] > x){
            high = min(high,v[i]);
            ans.second = high;
        }
        
    }
    return ans;
}