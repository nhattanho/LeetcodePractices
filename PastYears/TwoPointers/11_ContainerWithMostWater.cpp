/* Time complexity O(n), Sapce O(1) */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxArea = 0, flag = 0;
        for(int i = 0; i < len; i++){ //[1,8,6,2,5,4,8,3,7]
            maxArea = max(maxArea, min(height[i], height[len-1]) * (len-1-i) );
            if(height[i] >= height[len-1]){
                len--;
                i--;
            }
        }
        return maxArea;
    }
};
