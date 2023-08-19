//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // Greedy approach
    // I am solving so that if question is asked to store the meetings will also work
    
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    bool static comp(struct meeting m1, struct meeting m2){
        int e1 = m1.end;
        int e2 = m2.end;
        if(e1 < e2) return true;
        else if(e1 > e2) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i = 0; i < n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, comp);
        vector<int> ans;
        ans.push_back(meet[0].pos);
        int limit = meet[0].end;
        
        for(int i = 0; i < n; i++){
            if(meet[i].start > limit){
                ans.push_back(meet[i].pos);
                limit = meet[i].end;
            }
            else{
                continue;
            }
        }
        
        return ans.size();
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends