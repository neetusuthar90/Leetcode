class Solution {
public:
    vector<int> leftSmallElement(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                nse[i] = 0;
            }else{
                nse[i] = st.top()+1;
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> rightSmallElement(vector<int>& heights){
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                pse[i] = n-1;
            }else{
                pse[i] = st.top()-1;
            }
            st.push(i);
        }

        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        vector<int> leftSmall, rightSmall;

        leftSmall = leftSmallElement(heights);
        rightSmall = rightSmallElement(heights);

        for(int i = 0; i < heights.size(); i++){
            maxi = max(maxi, heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }

        return maxi;
    }
};