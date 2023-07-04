//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    typedef pair<int,int> Pair;
    
    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < N; i++){
            pq.push({arr[i],i});
        }
        
        int rank = 1;
        int prev = pq.top().first;
        
        while(!pq.empty()){
            if(prev != pq.top().first){
                rank++;
            }
            
            prev = pq.top().first;
            int idx = pq.top().second;
            
            pq.pop();
            arr[idx] = rank;
        }
        
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends