class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int src, vector<bool> &visited){
        visited[src] = true;
        for(int i = 0; i < isConnected[src].size(); i++){
            if(isConnected[src][i]==1 && !visited[i]){
                dfs(isConnected,i,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i = 0; i < n; i++){
            if(visited[i]==false){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }

};