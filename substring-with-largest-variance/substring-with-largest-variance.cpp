class Solution {
public:
    int largestVariance(string s) {
        int f1 = 0;
        int f2 = 0;

        int maxVar = 0;
        unordered_set<char> st(s.begin(), s.end());

        int run = 2;
        while(run--){
            for(char c1:st){
                for(char c2:st){
                    if(c1 == c2){
                        continue;
                    }

                    f1 = f2 = 0;
                    for(char letter:s){
                        if(letter == c1){
                            f1++;
                        }else if(letter == c2){
                            f2++;
                        }

                        if(f1 < f2){
                            f1 = f2 = 0;
                        }else if(f1 > 0 && f2 > 0){
                            maxVar = max(maxVar,f1-f2);
                        }
                    }
                }
            }
            reverse(s.begin(), s.end());
        }

        return maxVar;
    }
};