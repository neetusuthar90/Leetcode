class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int countofKeys = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        int x,y;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    maxLen = max(grid[i][j]-'a'+1, maxLen);
                }
                if(grid[i][j] == '@'){
                    x = i;
                    y = j;
                }
            }
        }
        unordered_set<string> visited;
        queue<vector<int>> q;
        // x, y are starting point coordinates , keys got so far;
        q.push({x,y,0});
        //if this string present means visited this much key so far at this coordinates
        visited.insert(to_string(x)+" "+to_string(y)+" "+to_string(0));

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        int dist = 0;

        while(!q.empty()){
            int size = q.size();
            
            for(int k = 0; k < size; k++){
                vector<int> curr = q.front();
                q.pop();

                if(curr[2] == (1 << maxLen)-1){
                    return dist;
                }

                for(int i = 0; i < 4; i++){
                    int nx = curr[0] + dx[i];
                    int ny = curr[1] + dy[i];
                    int keys = curr[2];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#'){
                        char ch = grid[nx][ny];

                        if(ch >= 'a' && ch <= 'f'){
                            //add the key
                            keys = keys | (1 << (ch-'a'));
                        }

                        // If it is a lock without key then continue
                        if(ch >= 'A' && ch <= 'F' && (1 << (ch-'A') & keys) == 0){
                            continue;
                        }

                        //else check if not visited then mark visited
                        if(!visited.count(to_string(nx)+" "+to_string(ny)+" "+to_string(keys))){
                            visited.insert(to_string(nx)+" "+to_string(ny)+" "+to_string(keys));
                            q.push({nx,ny,keys});
                        }

                    }
                    
                }
            }
            dist++;
        }
        return -1;
    }
};