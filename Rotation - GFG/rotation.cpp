//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0;
        int high = n-1;
        int minx = INT_MAX;
        int idx = 0;
        
        while(low <= high){
            int mid = (high+low)/2;
            
            if(arr[low] <= arr[mid]){
                if(arr[low] < minx){
                    minx = arr[low];
                    idx = low;
                }
                low = mid+1;
            }else{
                if(arr[mid] < minx){
                    minx = arr[mid];
                    idx = mid;
                }
                high = mid-1;
            }
        }
        
        return idx;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends