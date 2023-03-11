//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        if(n == 1){
            cout << n;
        }
        else{
            vector<int> out;
            for(int i = 1; i <= sqrt(n); i++){
                if(n%i == 0){
                    int x = n/i;
                    if(x == i){
                        out.push_back(i);
                    }
                    else{
                        out.push_back(i);
                        out.push_back(x);
                    }
                }
            }
            sort(out.begin(),out.end());
            for(int i = 0; i < out.size(); i++){
                cout << out[i] << " ";
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends