//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        //Write your code
        string str = "";
        solve(num, str);
        
    }
    void solve(int n, string str){
        if(n == 0){
            cout << str << " ";
            return;
        }
        solve(n-1, str+'0');
        if(str.back() != '1'){
            solve(n-1, str+'1');
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends