class Solution {
public:
   unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2) == 0){
            return true;
        }
        if(s1.length() <= 1){
            return false;
        }
        string key = s1;
        key.push_back('_');
        key.append(s2);
        if(mp.find(key) != mp.end()) return mp[key];

        int n =  s1.length();
        bool flag = false;
        for(int i = 1; i < n; i++){
            // Condition 1 when swap
            bool cond1 = isScramble(s1.substr(0,i), s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i), s2.substr(0,n-i));
            // Condition 2 when no swap
            bool cond2 = isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,n-i), s2.substr(i,n-i));
            if(cond1||cond2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
};