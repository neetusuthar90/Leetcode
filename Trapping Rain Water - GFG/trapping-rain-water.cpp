//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int low = 0;
        int high = n-1;
        int leftMax = 0;
        int rightMax = 0;
        long long res = 0;
        
        while(low <= high){
            if(arr[low] <= arr[high]){
                if(leftMax < arr[low]){
                    leftMax = arr[low];
                }
                else{
                    res += leftMax-arr[low];
                }
                low++;
            }
            else{
                if(rightMax < arr[high]){
                    rightMax = arr[high];
                }else{
                    res += rightMax - arr[high];
                }
                high--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends