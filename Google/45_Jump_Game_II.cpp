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

/*
Based on the above approach, at each element, we can find the start jump and the
maximum jump it can be jumped. However, between the start and max jump, there is exist
a potential jump. So, firstly, we need to find the potential jump for the next jump that
can be find by finding the maximum farthest we can jump.Secondly, whenever we reach the max
jump for each element, we know we need at least one jump to jump.
For example:

[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12]
 4   2   3   1   1   2   2   1   2   5    3    8    6

At the beginning, the max index we can jump is 4, means 0 -> 4. So, we can jump from:
0->1
0->2
0->3
0->4

So, if we go from 0 -> 4, mean we know exactly we need at least 1 jump. But we dont know 
what exactly position => we need to find the potential jump. And we check the farthest
will be 5 at position 2 or position 4 => farthest is updated to 5. So, if we go to i = 5,
==> we need 2 jump. In this case, we jump 0->4->5 or 0->2->5.

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        
        int check_jump = nums[0], farthest = 0, j = 0;
        for(int i = 0; i < size-1; i++){
            farthest = max(farthest, i+nums[i]);
            
            if(i == check_jump){
                j++;
                check_jump = farthest;
                if(farthest >= size-1) return ++j;
            }
        }
        /*case check_jump < size-1 <=> we will never reach the last index*/
        return (size == 1 || check_jump < size-1) ? 0:(j+1);
    }
};
