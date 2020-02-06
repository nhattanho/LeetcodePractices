/*Version1: Using A Linear Time Majority Vote Algorithm
http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for(auto num : nums) {
            if(count == 0) {
                count++;
                res = num;
            } else if(num == res) {
                count++;
            } else{
                count--;
            }
        }
        return res;
    }
};

/*Version2: Using map*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int l = nums.size();
        map<int,int>temp; //number,count
        for(auto a:nums) temp[a]++;
        map<int,int>::iterator it = temp.begin();
        int number = it->first;
        int count = it->second;
        
        for(auto a:temp){
            if(count < a.second){
                count = a.second;
                number = a.first;
            }
        }
        return number;
    }
};

/*Version3: Using unordered_map with additional compare function*/
class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> temp;
        for(auto a:nums) temp[a]++;
        auto res = max_element(temp.begin(), temp.end(), [](
             pair<int,int> a, 
             pair<int,int> b) -> bool { 
            return a.second < b.second; 
        });
        return res->first;
       
    }
};
