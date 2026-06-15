/* Let T is the target, M is the minimum of candidates array ==> the max length (depth+1) of this N-ary Tree is T/M.
As we know, with Binary Tree having the length equal T/M, the maximum total nodes is 2^(T/M) (Ignore for subtract by 1),
so, for N-ary Tree, this result will approximately be N^(T/M). Furthurmore, the array has N elements, and each element
created its own N-ary Tree having N^(T/M) nodes ==> the maximum of node can be created in an array N*N^(T/M) <=> Time 
complexity because we gonna use the Back Tracking Algorithm going through all nodes of the N-ary Tree. 
Space complexity <=> the maximum stacks we used for each time go to the end of one N-ary Tree <=> O(T/M) */

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int>path;// current sub array
        sort(can.begin(), can.end());
        findCombination(can, path, target, 0);
        return res;
    }
    void findCombination(vector<int>can, vector<int>path, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if (target < 0) return;
        
        for(int i = start; i < can.size(); i++){
            path.push_back(can[i]);
            target -= can[i];
            findCombination(can, path, target, i);
            target += can[i];
            path.pop_back();
        }
    }
};

/* Optimize for some cases */
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int>path;// current sub array
        sort(can.begin(), can.end());
        findCombination(can, path, target, 0);
        return res;
    }
    //  2  3  5 
    void findCombination(vector<int>can, vector<int>path, int target, int start){
        if(target < can[start]) return;
        for (int i = start; i < can.size(); i++){
            if(target > can[i]) {
                path.push_back(can[i]); 
                target -= can[i];// 
                findCombination(can, path, target, i);// [ 2 3 ]/3
                target += can[i]; 
                path.pop_back(); // []/8
            } else if (target == can[i]){
                path.push_back(can[i]); // 
                res.push_back(path);
                return;
            } else {
                return;
            }
        }
        
    }
};
