/*Using unordered_map with Time Complexity O(n), Space O(n)*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> temp;
        for(auto x:nums) temp[x]++;
        for(auto x: temp){
            if(x.second == 1) return x.first;
        }
        return 0;
    }
}

/*Using bit manipulation, Time Complexity O(n), Space O(1)*/
class Solution {
public:
    int singleNumber(vector<int>& nums){
            int ans = 0;
            for(auto x:nums) ans ^= x;
            return ans;
    }
};
