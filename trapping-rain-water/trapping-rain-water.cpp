class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while(low <= high){
            if(height[low] <= height[high]){
                if(leftMax < height[low]) leftMax = height[low];
                else{
                    ans += leftMax-height[low];
                }
                low++;
            }
            else{
                if(rightMax < height[high]) rightMax = height[high];
                else{
                    ans += rightMax-height[high];
                }
                high--;
            }
        }
        return ans;
    }
};