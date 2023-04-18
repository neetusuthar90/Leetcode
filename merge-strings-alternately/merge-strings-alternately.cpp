class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;
        string op = "";
        while(i<n && j < m){
            op += string() + word1[i]+ word2[j];
            i++;
            j++;
        }
        return op+word1.substr(i)+word2.substr(j);
    }
};