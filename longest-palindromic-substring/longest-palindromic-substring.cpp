class Solution {
public:
    string str = "";
    int len = 0;
    string longestPalindrome(string s) {
        for(int i = 0; i < s.length(); i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return str;
    }

    void expand(int l, int r, string S){
        int n = S.length();
        
        while(l >= 0 && r < n && S[l] == S[r]){
            if(r-l+1 > len){
                len = r-l+1;
                str = S.substr(l,len);
            }
            l--;
            r++;
        }

    }
};