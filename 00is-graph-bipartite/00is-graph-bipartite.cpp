class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorVec(n,-1);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(colorVec[i] == -1){
                colorVec[i] = 1;
                q.push(i);

                while(!q.empty()){
                    int u = q.front();
                    q.pop();

                    for(auto v:graph[u]){
                        if(colorVec[v] == -1){
                            colorVec[v] = 1 - colorVec[u];
                            q.push(v);
                        }
                        else if(colorVec[v] == colorVec[u]){
                            return false;
                        }
                    }
                }        
            }
        }
        return true;
    }
};