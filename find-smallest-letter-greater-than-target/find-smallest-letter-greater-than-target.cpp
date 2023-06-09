class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i = 0; i < letters.size(); i++){
            char cur = letters[i];
            if(int(cur) > int(target)){
                return cur;
            }
        }
        return letters[0];
    }
};