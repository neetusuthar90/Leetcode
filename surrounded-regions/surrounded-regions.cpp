class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[x][y] = 1;

        int n = board.size();
        int m = board[0].size();

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && board[nx][ny] == 'O'){
                dfs(nx,ny,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        // traverse first row and last row
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,board,vis);
            }

            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis);
            }
        }

        // traverse first col and last col
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis);
            }

            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};