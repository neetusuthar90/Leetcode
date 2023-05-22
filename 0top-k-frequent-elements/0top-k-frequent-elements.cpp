class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        vector<pair<int,int>> vec;

        for(auto& it:mp){
            vec.push_back(it);
        }

        std::sort(vec.begin(), vec.end(), cmp);
        vector<int> res;

        int j = 0;
        while(k > 0){
            res.push_back(vec[j].first);
            j++;
            k--;
        }
        return res;
    }

};
