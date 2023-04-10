class Solution {
public:
    bool isGoodPair(char &a, char &b){
        if((a=='(' && b == ')')||(a=='[' && b==']')||(a=='{'&& b=='}')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty()&&(s[i]==']'||s[i]==')'||s[i]=='}')){
                return false;
            }
            else if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else if(isGoodPair(st.top(),s[i])){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};