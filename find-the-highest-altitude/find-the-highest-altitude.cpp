class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int highest = INT_MIN;
        int temp = 0;
        for(int i = 0; i < n; i++){
            highest = max(highest, temp);
            temp = temp + gain[i];
        }
        if(temp > highest){
            highest = temp;
        }
        return highest;
    }
};