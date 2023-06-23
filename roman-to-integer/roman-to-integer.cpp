class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int n = s.length();
        int res = 0;
        res += mp[s[n-1]];

        for(int i = n-2; i >= 0; i--){
            cout << res << endl;
            if(mp[s[i+1]] > mp[s[i]]){
                res = res - mp[s[i]];
            }else{
                res = res + mp[s[i]];
            }
        }

        return res;
    }
};