class Solution {
public:
    string removeStars(string s) {
        int cnt = 0;
        string op = "";
        int n = s.length();
        for(int i = n-1; i>=0; i--){
            if(s[i]=='*'){
                cnt++;
            }
            else{
                if(cnt>0){
                    cnt--;
                }
                else{
                    op += s[i];
                }
            }
        }
        reverse(op.begin(),op.end());
        return op;
    }
};