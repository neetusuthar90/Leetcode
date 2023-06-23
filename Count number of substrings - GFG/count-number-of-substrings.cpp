//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int helper(string &s, int k){
        if (s.size() == 0) {
            return 0;
        }
        
        long long int ans = 0;
    	vector<int> mp(26,0);
    	
    	int i = 0, j = 0;
    	int count = 0;
    	
    	while(j < s.length()){
    	    if(mp[s[j]-'a'] == 0){
    	        count++;
    	    }
    	    mp[s[j]-'a']++;
    	    
    	    while(count > k){
    	        mp[s[i]-'a']--;
    	        if(mp[s[i]-'a'] == 0){
    	            count--;
    	        }
    	        i++;
    	    }
    	    j++;
    	    ans += j-i+1;
    	}
    	return ans;
    }
    
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	return helper(s,k) - helper(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends