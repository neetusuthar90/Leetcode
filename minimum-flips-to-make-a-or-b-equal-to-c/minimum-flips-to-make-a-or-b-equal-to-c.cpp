class Solution {
public:
    int minFlips(int x, int y, int z) {
        bitset<32> a(x), b(y), c(z);
        int count = 0;
        for(int i = 0; i < 32; i++){
            if(c[i]==1){
                if(a[i]==0 && b[i]==0){
                    count++;
                }
            }
            else{
                if(a[i]==1){
                    count++;
                }
                if(b[i]==1){
                    count++;
                }
            }
        }
        return count;
    }
};