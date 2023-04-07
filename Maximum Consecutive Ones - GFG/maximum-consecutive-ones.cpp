//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int maxlen = 0;
        int left = 0;
        int right = 0;
        while(right<n){
            if(nums[right] == 1){
                maxlen = max(maxlen,right-left+1);
                right++;
            }
            else if(nums[right] == 0){
                if(k>0){
                    k--;
                    maxlen = max(maxlen,right-left+1);
                    right++;
                }
                else if(k==0){
                    while(nums[left]==1){
                        left++;
                    }
                    left++;
                    k++;
                }
            }
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends