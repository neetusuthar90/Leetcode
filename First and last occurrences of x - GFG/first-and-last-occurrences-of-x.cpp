//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first(int arr[], int n , int x ){
    int ans = -1;
    int st = 0;
    int ed = n-1;
    while(st <= ed){
        int mid = (st+ed)/2;
        if(arr[mid] == x){
            ans = mid;
            ed = mid -1;
        }
        else if(arr[mid] < x){
            st = mid+1;
        }
        else{
            ed = mid-1;
        }
    }
    return ans;
}
int last(int arr[], int n , int x ){
    int ans = -1; 
    int st = 0;
    int ed = n-1;
    while(st <= ed){
        int mid = (st+ed)/2;
        if(arr[mid] == x){
            ans = mid;
            st = mid+1;
        }
        else if(arr[mid] < x){
            st = mid+1;
        }
        else{
            ed = mid-1;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    vector<int> res;
    res.push_back(first(arr,n,x));
    res.push_back(last(arr,n,x));
    return res;
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends