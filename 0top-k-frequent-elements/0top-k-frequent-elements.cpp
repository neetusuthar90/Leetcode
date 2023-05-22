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

        priority_queue<pair<int, int>> pq;

        for(auto it:mp){
            pq.push(make_pair(it.second, it.first));
        }

        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }

};
