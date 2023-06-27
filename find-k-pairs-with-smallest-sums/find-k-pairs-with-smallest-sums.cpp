class Solution {
public:

    // static bool compare(pair<int,int> &p1, pair<int,int> &p2){
    //     int sum1 = p1.first + p1.second;
    //     int sum2 = p2.first + p2.second;

    //     if(sum1 > sum2){
    //         return true;
    //     }
    //     return false;
    // }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> ans;
        
        pq.push({nums1[0]+nums2[0], {0,0}});

        while(!pq.empty() && ans.size() < k){
            auto p = pq.top();
            pq.pop();

            int i = p.second.first;
            int j = p.second.second;

            ans.push_back({nums1[i], nums2[j]});
            
            if(i == 0 && j+1 < nums2.size()){
                int x = nums1[i] + nums2[j+1];
                pq.push({x,{i,j+1}});
            }

            if(i+1 < nums1.size()){
                int y = nums1[i+1] + nums2[j];
                pq.push({y,{i+1, j}});
            }
        }

        return ans;
    }
};