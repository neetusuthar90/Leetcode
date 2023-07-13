class DisjointSet{
public:
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map <int,int> stoneNodes;

        for(auto it:stones){
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            ds.unionbyRank(rowNode,colNode);
            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int cntComp = 0;
        for(auto it:stoneNodes){
            if(ds.findPar(it.first) == it.first){
                cntComp++;
            }
        }

        return stones.size() - cntComp;
    }
};