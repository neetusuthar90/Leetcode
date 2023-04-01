class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> res;
        stack<int> st;
        int i = 0;
        while(i < n){
            if(st.empty()){
                st.push(ast[i]);
                i++;
            }
            else{
                if(st.top()>0 && ast[i]>0 || st.top()<0 && ast[i]<0 || st.top()<0 && ast[i]>0){
                    st.push(ast[i]);
                    i++;
                }
                else if(st.top()>0 && ast[i]<0){
                    int a = st.top();
                    st.pop();
                    if(abs(ast[i])==a){
                        i++;
                    }
                    else if(abs(ast[i]) > a){
                        continue;
                    }
                    else{
                        st.push(a);
                        i++;
                    }
                }
            }
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};