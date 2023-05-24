class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        //make pair
        for(int i=0;i<nums1.size();i++)
            vec.push_back({nums2[i],nums1[i]});
        //sort on base of nums2 in descending order
        sort(vec.rbegin(),vec.rend());
        
        long long ans = 0;
        long long curr_sum = 0;
        
        //make k-1 element min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k-1;i++){
            curr_sum += vec[i].second;
            pq.push(vec[i].second);
        }
            
        
        // loop in sorted array from k to array size, taking current element as min and 
        // try to maximize sum of 1st array elements
        for(int i=k-1;i<nums1.size();i++){
            //include ith element to subsequence
            curr_sum+=vec[i].second;
            pq.push(vec[i].second);
            ans = max(ans,curr_sum * vec[i].first);
            //remove min element from priority queue
            curr_sum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};