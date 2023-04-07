//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int n = S.length();
        if(n==0){
            return 0;
        }
        int maxlen = 0;
        vector<int> mpp(256,-1);
        int left = 0;
        int right = 0;
        while(right<n){
            if(mpp[S[right]] != -1){
                left = max(mpp[S[right]]+1, left);
            }
            mpp[S[right]] = right;
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends