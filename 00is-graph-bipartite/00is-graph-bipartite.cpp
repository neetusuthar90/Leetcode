class Solution {
public:
    //DFS Traversal
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,0);

        for(int node = 0; node<n; node++){
            if(colour[node] == 0 && !DFS(graph, colour, node, 1)){
                return false;
            }
        }
        return true;
    }

    bool DFS(vector<vector<int>>& graph, vector<int> &colour, int node, int c){
        if(colour[node] != 0){
            return (colour[node]==c);
        }
        colour[node] = c;
        for(auto nbd:graph[node]){
            if(!DFS(graph,colour,nbd,-c)){
                return false;
            }
        }
        return true;
    }
};