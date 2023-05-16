class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j=0;
        int maxi = 0;

        unordered_map<char, int> mp;

        while(j < s.length()){
            mp[s[j]]++;

            if(mp.size()>j-i+1){ //This condtition will never hit we wrote this just for the pattern of sliding window technique
                j++;
            }

            else if(mp.size()==j-i+1){
                maxi = max(maxi, j-i+1);
                j++;
            }

            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};