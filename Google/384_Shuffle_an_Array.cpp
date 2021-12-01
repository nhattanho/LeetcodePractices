class Solution {
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> sh = arr;
        for(int i = sh.size()-1; i > 0; i--){
            /*random position from 0->i*/
            int temp = rand()%(i+1);
            swap(sh[i], sh[temp]);
        }
        return sh;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
