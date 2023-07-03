class Solution {
public:
    // Points to remember that any node which is a part of a cycle or leads to the cycle
    // through an incoming edge towards the cycle, cannot be a safe node.
    // Apart from these types of nodes, every node is a safe node.
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        vector<int> indegree(graph.size(), 0);

        for(int i = 0; i < graph.size(); i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> safeNodes;
        queue<int> q;
        
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);
            for(auto it:adj[node]){
                if(indegree[it] > 0){
                    indegree[it]--;
                }
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};