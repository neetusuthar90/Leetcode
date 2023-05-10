class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> ip;
        for(int i = 1; i <= n*n; i++){
            ip.push_back(i);
        }

        vector<vector<int>> op(n, vector<int>(n));

        int direction = 1;
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        int k = 0;

        while(k < n*n){
            switch(direction){
                case 1:
                    for(int i = left; i <= right; i++){
                        op[top][i] = ip[k];
                        k++;
                    }
                    direction = 2;
                    top++;
                    break;
                
                case 2:
                    for(int i=top; i <= bottom; i++){
                        op[i][right] = ip[k];
                        k++;
                    }
                    direction = 3;
                    right--;
                    break;

                case 3:
                    for(int i = right; i>= left; i--){
                        op[bottom][i] = ip[k];
                        k++;
                    }
                    direction = 4;
                    bottom--;
                    break;

                case 4:
                    for(int i = bottom; i>=top; i--){
                        op[i][left] = ip[k];
                        k++;
                    }
                    direction = 1;
                    left++;
                    break;
            }
        }
        return op;
    }
};