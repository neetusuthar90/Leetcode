class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto nbr:adj[node]){
                if(indegree[nbr]>0){
                    indegree[nbr]--;
                }

                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        if(ans.size() != numCourses){
            //Cycle present means topo sort not possible
            return {};
        }
        return ans;
    }
};