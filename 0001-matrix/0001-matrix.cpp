class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int> (m,0));
        vector<vector<int>> vis(n, vector<int> (m,0));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;

            int step = q.front().second;
            q.pop();

            ans[x][y] = step;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny}, 1 + step});
                }
            }
        }

        return ans;
    }
};