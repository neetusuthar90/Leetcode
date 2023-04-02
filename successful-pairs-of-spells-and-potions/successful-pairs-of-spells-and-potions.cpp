class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> op;
        
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++){
            long c = (success+spells[i]-1)/spells[i];
            int low = 0;
            int high = m-1;
            int idx = m;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(potions[mid] >= c){
                    idx = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            int count = m-idx;
            op.push_back(count);
        }
        return op;
    }
};