class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n,-1);
        for(int i = 2*n-1; i >= 0; i--){
            int m = nums[i%n];
            while(!st.empty() && m >= st.top()){
                st.pop();
            }
            if(i<n && !st.empty()){
                nge[i%n] = st.top();
            }
            st.push(m);
        }
        return nge;
    }
};