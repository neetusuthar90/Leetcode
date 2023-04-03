class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        //Instead of using sorting we are using counting sort
        vector<int> count(limit+1,0);
        for(auto p:people){
            count[p]++;
        }
        int idx = 0;
        for(int val = 1; val <= limit; val++){
            while(count[val] > 0){
                people[idx++] = val;
                count[val]--; 
            }
        }
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            if(people[low]+people[high] <= limit){
                high--;
                low++;
            }
            else{
                high--;
            }
            ans++;
        }
        return ans;
    }
};