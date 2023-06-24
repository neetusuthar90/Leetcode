class Solution {
public:
    string reverseWords(string S) {
        string ans = "";
        string temp = "";
        stack<string> st;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == ' '){
                if(temp != ""){
                    st.push(temp);
                }
                temp = "";
            }else{
                temp += S[i];
            }
        }
        //reverse(temp.begin(), temp.end());
        if(temp!=""){
           st.push(temp);
        }

        while(!st.empty()){
            ans += (st.top() + " ");
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};