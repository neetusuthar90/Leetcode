//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    private:
        bool static comp(Job j1, Job j2){
            if(j1.profit > j2.profit) return true;
            else if(j1.profit < j2.profit) return false;
            else if(j1.dead > j2.dead) return true;
            else return false;
        }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        
        int maxdeadline = 1;
        for(int i = 0; i < n; i++){
            maxdeadline = max(maxdeadline, arr[i].dead);
        }
        vector<int> vis(maxdeadline + 1, -1);
        
        int profit = 0;
        int jobsComp = 0;
        for(int i = 0; i < n; i++){
            int deadline = arr[i].dead;
            if(vis[deadline] == -1){
                vis[deadline] = arr[i].id;
                profit += arr[i].profit;
                jobsComp += 1;
            }
            else{
                while(vis[deadline] != -1 && deadline > 1){
                    deadline--;
                }
                if(vis[deadline] == -1){
                    vis[deadline] = arr[i].id;
                    profit += arr[i].profit;
                    jobsComp += 1;
                }
            }
        }
        
        return {jobsComp, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends