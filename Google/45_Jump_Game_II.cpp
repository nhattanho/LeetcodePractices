/* Idea:
https://www.youtube.com/watch?v=DxsCg0mn-4s
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        
        for(int i = 0; i < size; i++){
            int max = i+nums[i];
            if(max >= size - 1) return ++j;
            int temp = 0,  mark = 0;
            for(int start = i+1; start <= max; start++){
                if(start + nums[start] > temp) {
                    temp = start+nums[start];
                    mark = start;
                }
            }
            j++;
            i = mark-1;
        }
        return j;
    }
};
