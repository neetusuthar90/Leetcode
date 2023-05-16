class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto it:t){
            mp[it]++;
        }
        int count = mp.size();

        int i = 0, j=0;
        int ans = INT_MAX;
        int min_i = 0;

        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
        }

        while(j < s.length()){
            if(count > 0){
                j++;
                if(mp.find(s[j]) != mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        count--;
                    }
                }
            }
            else if(count == 0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    min_i = i;
                }
                while(count == 0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            if(ans>j-i+1){
                                ans = j-i+1;
                                min_i = i;
                            }
                        }
                        i++;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        string str = "";
        if(ans != INT_MAX){
            return str.append(s.substr(min_i,ans));
        }
        return str;
    }
};