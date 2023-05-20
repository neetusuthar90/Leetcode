class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr = buildGraph(equations,values);
        vector<double> finalAns;

        for(auto query: queries){
            string dividend = query[0];
            string divisor = query[1];

            if(gr.find(dividend)==gr.end() || gr.find(divisor) == gr.end()){
                finalAns.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                double ans = -1.0, temp = 1.0;
                DFS(dividend,divisor,gr,vis,ans,temp);
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map<string, unordered_map<string, double>> gr;

        for(int i = 0; i < equations.size(); i++){
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1.0/value;
        }

        return gr;
    }

    void DFS(string node, string &dest, unordered_map<string, unordered_map<string, double>> &gr, unordered_set<string> &vis, double& ans, double temp){
        if(vis.find(node) != vis.end()) return;

        vis.insert(node);
        if(node == dest){
            ans = temp;
            return;
        }

        for(auto nb:gr[node]){
            DFS(nb.first, dest, gr, vis, ans, temp*nb.second);
        }
    }
};