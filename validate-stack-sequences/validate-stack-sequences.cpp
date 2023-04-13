class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        int n = pushed.size();
        int j = 0;
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            st.push(pushed[i]);
        }
        while(!st.empty() && st.top()==popped[j]){
            st.pop();
            j++;
        }
        return st.empty();
    }
};