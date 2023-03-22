class Solution {
public:
    void preparedList(unordered_map<int, list<pair<int,int>>> &adj, vector<vector<int>>& roads){
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int,int>>> adj;
        preparedList(adj,roads);
        queue<int> q;
        q.push(1);
        vector<int> visited(n+1,0);
        visited[1] = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            for(auto nbd:adj[fNode]){
                ans = min(ans, nbd.second);
                if(visited[nbd.first] == 0){
                    visited[nbd.first] = 1;
                    q.push(nbd.first);
                }
            }
        }
        return ans;
    }
};