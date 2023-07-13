class DisjointSet{
public:
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionbyRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
            rank[pu]++; 
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtra = 0;
        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];

            if(ds.findPar(u) == ds.findPar(v)){
                countExtra++;
            }else{
                ds.unionbyRank(u,v);
            }
        }

        int countComp = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                countComp++;
            }
        }

        int ans = countComp-1;
        if(countExtra >= ans) return ans;
        return -1;
    }
};