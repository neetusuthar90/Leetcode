class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> res(nums1.size(),-1);
        for(auto m:nums2){
            while(!st.empty() && m>st.top()){
                mp[st.top()] = m;
                st.pop();
            }
            st.push(m);
        }
        for(int i = 0; i < nums1.size(); i++){
            if(mp.find(nums1[i]) != mp.end()){
                res[i] = mp[nums1[i]];
            }
        }
        return res;
    }
};