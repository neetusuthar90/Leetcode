class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid.size()==0 || grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }
        if(grid.size()==1 && grid[0][0]==0){
            return 1;
        }

        queue<pair<pair<int,int>,int>> todo;
        todo.push({{0,0},1});

        vector<vector<bool>> visited;
        visited.resize(n, vector<bool>(n,false));
        vector<pair<int,int>> neighbours = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},
                                            {-1,1},{1,-1},{1,1}};

        visited[0][0] = true;

        while(!todo.empty()){
            pair<int,int> p = todo.front().first;
            int dist = todo.front().second;

            todo.pop();
            int x = p.first;
            int y = p.second;
            
            
            for(pair<int,int> nbr:neighbours){

                int newx = nbr.first + x;
                int newy = nbr.second + y;

                if(newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy]==0 && !visited[newx][newy]){
                    todo.push({{newx,newy},dist+1});
                    visited[newx][newy] = true;
                    
                    if(newx == n-1 && newy == n-1){
                        return dist+1;
                    }
                }
            }
        }
        return -1;
    }
};