/* Brute Force, Time complexity O(n^2), Space O(1) */
class Solution 
{
private:
    vector<int>result;    
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

/* Using map to reduce Time complexity to O(n), Space O(n) */
class Solution
{
private:
    vector<int>result;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int,int>temp;//value, position
        int remain;
        for(int i = 0; i < nums.size(); i++){
            remain = target-nums[i];
            if(!temp.count(remain)) temp.insert({nums[i], i});
            else{
                res.push_back(i);
                res.push_back(temp[remain]);
                return res;
            }
        }
        return res;
    }
};
