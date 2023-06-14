//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //Two important properties of XOR are the following:
	    //XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
	    //XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2
	    int xorr = 0;
	    for(int i = 0; i < N; i++){
	        xorr = xorr^A[i]; 
	    }
	    return xorr;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends