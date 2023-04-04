class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        unordered_set<char> st;
        int count = 1;
        for(int i = 0; i<n; i++){
            if(st.find(s[i]) != st.end()){
                //element found
                count++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return count;
    }
};