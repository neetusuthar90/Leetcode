//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int low, int high, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int idx = -1;
        while(low <= high){
            int mid = (high+low)/2;
            if(arr[mid] == key){
                return mid;
            }
            
            if(arr[low] <= arr[mid]){
                // Left half is sorted
                if(arr[low] <= key && arr[mid] >= key){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            else{
                // left half not sorted and right half sorted
                if(arr[mid] <= key && arr[high] >= key){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return idx;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends