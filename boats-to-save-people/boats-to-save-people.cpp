class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            if(people[low]+people[high] <= limit){
                low++;
            }
            ans++;
            high--;
        }
        return ans;
    }
};