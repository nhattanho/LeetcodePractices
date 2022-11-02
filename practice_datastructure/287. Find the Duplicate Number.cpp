class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = nums[0], fast = nums[0];
        low = nums[low];
        fast = nums[low];
        while(low != fast){
            low = nums[low];
            fast = nums[nums[fast]];
        }
        low = nums[0];
        while(low != fast){
            low = nums[low];
            fast = nums[fast];
        }
        return low;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size()+1;
        bool *arr = new bool[len]{false};
        
        for(int i = 0; i < len; i++){
            int pos = nums[i];
            if(arr[pos] == false) arr[pos] = true;
            else return pos;
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int fast = nums[0], slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }while(fast!=slow);
        slow = nums[0];
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
