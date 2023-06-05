class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==2){
            return true;
        }
        int ans;
        for(int i = 0; i < n-2; i++){
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            int x2 = coordinates[i+1][0];
            int y2 = coordinates[i+1][1];
            int x3 = coordinates[i+2][0];
            int y3 = coordinates[i+2][1];
            
            if((x2-x1) != 0 && (x3-x2) != 0 && (x3-x1) != 0){
                int slope1 = (y2-y1)/(x2-x1);
                int slope2 = (y3-y2)/(x3-x2);
                int slope3 = (y3-y1)/(x3-x1);

                if(slope1 == slope2 && slope2 == slope3 && slope3 == slope1){
                    ans = true;
                }
                else{
                    return false;
                }
            }
            else if((x1 == x2 && x2 == x3 && x3 == x1) || (y1 == y2 && y2 == y3 && y1 == y3)){
                ans = true;
            }
            else{
                return false;
            }
            
        }
        return ans;
    }
};