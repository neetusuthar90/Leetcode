class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adj[n];
        vector<int> indegree(n,0);
        // Reverse the direction
        for(int i = 0; i<n; i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> safenodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safenodes.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};