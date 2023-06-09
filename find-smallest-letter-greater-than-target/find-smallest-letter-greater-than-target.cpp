class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;

        while(low < high){
            int mid = (low+high)/2;
            if((letters[mid]-'a') <= (target-'a')){
                //shift to right
                low = mid+1;
            }
            else{
                //shift to left
                high = mid;
            }
        }

        if(letters[low]-'a' > target-'a'){
            return letters[low];
        }
        return letters[0];
    }
};