//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        if(n == 0){
            return "";
        }
        if(n == 1){
            return arr[0];
        }
        sort(arr, arr+n);
        int mn = min(arr[0].size(), arr[n-1].size());
        string first = arr[0], last = arr[n-1];
        int i = 0;
        while(i < mn && first[i] == last[i]){
            i++;
        }
        if(i == 0){
            return "-1";
        }
        string ans = first.substr(0,i);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends