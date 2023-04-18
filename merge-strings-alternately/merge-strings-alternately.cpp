class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;
        string op = "";
        while(i<n && j < m){
            op = op + word1[i];
            op = op + word2[j];
            i++;
            j++;
        }
        while(i<n){
            op += word1[i];
            i++;
        }
        while(j<m){
            op += word2[j];
            j++;
        }
        return op;
    }
};