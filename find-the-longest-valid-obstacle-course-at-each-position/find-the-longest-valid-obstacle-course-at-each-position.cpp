class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> temp;
        vector<int> lislen(obstacles.size());

        temp.push_back(obstacles[0]);
        lislen[0] = 1;

        for(int i = 1; i < obstacles.size(); i++){
            int val = obstacles[i];
            if(temp.back() <= val){
                temp.push_back(val);
                lislen[i] = temp.size();
            }
            else{
                int idx = upper_bound(temp.begin(), temp.end(), val)-temp.begin();
                temp[idx] = val;
                lislen[i] = idx+1;
            }
        }
        return lislen;
    }
};