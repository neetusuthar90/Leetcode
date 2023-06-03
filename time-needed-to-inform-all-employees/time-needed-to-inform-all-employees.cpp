class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headId, adj, informTime);
    }

    int dfs(int headId, vector<vector<int>> &adj, vector<int> &informTime){
        int maxTime = 0;

        for(auto it:adj[headId]){
            maxTime = max(maxTime, dfs(it,adj,informTime));
        }

        return informTime[headId]+maxTime;
    }
};