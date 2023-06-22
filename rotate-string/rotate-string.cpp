class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        int n = s.length();
        string str = s + s;
        if(str.find(goal) != string::npos){
            return true;
        }

        return false;
    }
};