class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch != '*'){
                st.push(ch);
            }
            else if(ch == '*'){
                st.pop();
            }
        }
        string str = "";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};