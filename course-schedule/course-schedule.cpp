class Solution {
public:
    vector<int> topOrdering;

    bool topoSort(int numCourses, vector<int> adj[], vector<int> &indegree){

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topOrdering.push_back(node);

            for(auto nbr:adj[node]){
                if(indegree[nbr]>0){
                    indegree[nbr]--;
                }

                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        if(topOrdering.size() != numCourses){
            //Cycle present means topo sort not possible
            return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            for(auto nbr:adj[i]){
                indegree[nbr]++;
            }
        }

        bool ans = topoSort(numCourses, adj, indegree);

        return ans;
    }
};