class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double d = succProb[i];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<double> dist(n, 0.0);

        priority_queue<pair<double, int>> pq;

        //dist[start] = 1.0;

        pq.push({1.0, start});

        while(!pq.empty()){
            int node = pq.top().second;
            double prob  = pq.top().first;
            
            pq.pop();

            for(auto nbr:adj[node]){
                int newNode = nbr.first;
                double newProb = nbr.second;

                if(prob*newProb > dist[newNode]){
                    dist[newNode] = prob*newProb;
                    pq.push({dist[newNode],newNode});
                }
            }
        }

        return dist[end];

    }
};