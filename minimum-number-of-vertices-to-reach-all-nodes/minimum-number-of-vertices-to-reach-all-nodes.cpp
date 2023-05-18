class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n,0);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};