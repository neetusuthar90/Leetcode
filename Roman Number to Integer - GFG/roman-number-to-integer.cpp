//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<char,int> mp = {{'I',1}, {'V',5}, {'X',10}, {'L', 50}, {'C',100}, {'D',500},{'M',1000}};
        
        int n = str.length();
        int res = mp[str[n-1]];
        
        for(int i = n-2; i >= 0; i--){
            if(mp[str[i]] < mp[str[i+1]]){
                res = res - mp[str[i]];
            }else{
                res = res + mp[str[i]];
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends