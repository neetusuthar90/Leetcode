//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long sign = ((dividend < 0)^(divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long quotient = 0;
        for(int i = 31; i >= 0; i--){
            if((divisor << i) <= dividend){
                dividend -= (divisor<<i);
                quotient = quotient | 1LL << i;
            }
        }
        if(sign == -1) quotient = -quotient;
        return quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends