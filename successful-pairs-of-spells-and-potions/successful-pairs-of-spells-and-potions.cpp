class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> op;
        
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++){
            long c = (success+spells[i]-1)/spells[i];
            auto idx = lower_bound(potions.begin(), potions.end(),c);
            int count = potions.end()-idx;
            op.push_back(count);
        }
        return op;
    }
};