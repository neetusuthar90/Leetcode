class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        int n = s.length();
        int count1[26] = {0}, count2[26] = {0};

        for(int i = 0; i < n; i++){
            count1[s[i]-'a']++;
            count2[t[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};