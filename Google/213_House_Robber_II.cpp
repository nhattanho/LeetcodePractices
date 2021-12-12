class Solution {
public:
    int getMax(int start, int end, vector<int>nums){
        if(start == end) return nums[start];
        if(end - start == 1) return max(nums[start], nums[end]);
        int t1 = nums[start];
        int t2 = max(nums[start+1], nums[start]);
        
        for(int i = start+2; i <= end; i++){
            nums[i] = max(t2, t1+nums[i]);
            t1 = t2;
            t2 = nums[i];
        }
        return nums[end];
        
    }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        //get max1
        int max1 = getMax(0, size-2, nums);
        int max2 = getMax(1, size-1, nums);
        return max(max1, max2);
        
    }
};

/*Other way*/
public:
    int getMax(int start, int end, vector<int>nums){
        if(start == end) return nums[start];
        if(end - start == 1) return max(nums[start], nums[end]);
        nums[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i <= end; i++){
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        return nums[end];  
    }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        int max1 = getMax(0, size-2, nums);
        int max2 = getMax(1, size-1, nums);
        return max(max1, max2);
        
    }
};
