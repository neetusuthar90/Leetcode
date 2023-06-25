class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // we will probably not need many operations ?
        if(num1 <= num2 ) return -1;
        if(num1 == 0) return 0;
        for(int l =0;l <= 100; l+=1){
            long long diff = (long long)num1 - (long long)l*num2;
            if(diff < 0) return -1;
            //can this be written as sum of k bits
            if(__builtin_popcountll(diff)>l) continue;
            if(diff>=l) return l;
        }
        return -1;
    }
};