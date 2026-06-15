class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        int len = can.size();
        vector<vector<int>>res;
        if(len == 0) return res;
        sort(can.begin(), can.end());
        vector<int>path;                             // 0 1 2 3
        findCombination(res, can, path, target, 0); // [2 3 6 7] target = 9
        return res;
    }
    
    void findCombination(vector<vector<int>>&res, vector<int> can, vector<int> path, int target, int start) {// 2/5
        if(target < 0) return;
        if(target == 0) {
            res.push_back(path);
            return;
        }
        
        for(int i = start; i < can.size(); i++){
            if(i > start && can[i] == can[i-1]) continue;
            path.push_back(can[i]);
            target -= can[i];
            findCombination(res, can, path, target, i+1);
            target += can[i];
            path.pop_back();
        }
        return;
    }
};

/* The better performance though it has the same Time complexity and Space complexity as the previous one 
When finding the invalid sub or the target sub array, it gonna return immediately instead of going through
all the rest elements of original array */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        int len = can.size();
        vector<vector<int>>res;
        if(len == 0) return res;
        sort(can.begin(), can.end());
        vector<int>path;                    
        findCombination(res, can, path, target, 0); // [2 3 6 7] target = 9
        return res;
    }
    
    void findCombination(vector<vector<int>>&res, vector<int> can, vector<int> path, int target, int start) {// 2/5
        if(start == can.size() || target < can[start]) return;
        for (int i = start; i < can.size(); i++) {
            if (i > start && can[i] == can[i-1]) continue;
            if(target > can[i]){
                path.push_back(can[i]); 
                target -= can[i];
                findCombination(res, can, path, target, i+1); // target = 1 i = 0 start = 1
                target += can[i];
                path.pop_back(); 
            }else if (target < can[i]) {
                return;
            } else{
                path.push_back(can[i]);
                res.push_back(path);
                return;
            }
        }
        return;
    }
};
