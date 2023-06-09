class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> alpha(26,0);
        for(int i = 0; i < letters.size(); i++){
            alpha[letters[i]-'a']++;
        }
        int idx = (target-'a'+1)%26;
        while(alpha[idx] == 0){
            idx = (idx+1)%26;
        }
        return 'a'+idx;
    }
};