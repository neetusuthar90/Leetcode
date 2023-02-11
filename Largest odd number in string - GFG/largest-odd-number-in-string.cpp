//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        int len = s.length();
        string ans = "";
        if(len == 0){
            return ans;
        }
        int num;
        for(int i = len-1; i >= 0; --i){
            num = (int) s[i];
            if(num%2 != 0){
                //Odd
                ans += s.substr(0,i+1);
                break;
            }
        }
        return ans;
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

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends