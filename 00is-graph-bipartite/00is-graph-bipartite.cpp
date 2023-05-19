class Solution {
public:
    //BFS TRAVERSAL
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,0);
        

        for(int node=0; node<n; node++){
            if(colour[node]!=0) continue;

            queue<int> q;
            colour[node] = 1;
            q.push(node);

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v:graph[u]){
                    if(colour[v]==0){
                        //Not coloured yet
                        colour[v] = -colour[u];
                        q.push(v);
                    }
                    else if(colour[v] == colour[u]){
                        // OR colour[v] != -colour[u]
                        //Coloured is not as expected
                        return false;
                    }
                }
            }
        }
        return true;
    }
};