/* Naive Solution using Brute Force, time complexity O(n), space O(1) */
class Solution {
public:
    // 0 1 2 3 4 5 6 
    //[4,5,6,7,0,1,2]
    int search(vector<int>& nums, int target) {
        //values unique
        //rotated at some pivot
        int len = nums.size();
        for(int i = 0; i < len; i++)
            if(target == nums[i]) return i;
        return -1;
    }
};

/* The funny solution using recursive function, time complexity O(n), space O(logn) */
class Solution {
public:
    // 0 1 2 3 4 5 6
    //[4,5,6,7,0,1,2]
    int search(vector<int>& num, int target) {
        //values unique
        //rotated at some pivot
        int len = num.size();
        int l = 0;
        int r = len-1;
        int res = -1;
        getRes(num, target, l, r, res);
        return res;
    }
    
    void getRes (vector<int>num, int target, int l, int r, int& res){
        if(l > r) return;
        int mid = (l+r)/2;
        if(num[mid] == target){
            res = mid;
            return;
        }// l = r
        getRes(num, target, l, mid-1, res);
        getRes(num, target, mid+1, r, res);
    }
};

/* Optimal Solution by using Binary Search, time complexity O(logn), space O(1) */
class Solution {
public:
    // 0 1 2 3 4 5 6
    //[4,5,6,7,0,1,2]
    int search(vector<int>& num, int target) {
        int l = 0, r = num.size()-1, mid = 0;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(num[mid] == target) return mid;
            if(target == num[l]) return l;
            
            if (num[mid] >= num[l]){ // the left part of middle has to be increased [2,3,4,5,6,7,0,1]
                if(target < num[l]) l = mid + 1;
                else {
                    if(target < num[mid]) r = mid - 1;
                    else l = mid + 1;
                }
            } else {
                if(target >= num[l]){
                    r = mid - 1;
                }else {
                    if(target < num[mid]){
                        r = mid - 1;
                    }else {
                        l = mid + 1;
                    }
                }
            } 
        }
        return -1;
    }
};

/* ==> More concise Binary Search */
class Solution {
public:
    // 0 1 2 3 4 5 6
    
    //[4,5,6,7,0,1,2]
    int search(vector<int>& num, int target) {
        int l = 0, r = num.size()-1, mid = 0;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(num[mid] == target) return mid;
            if(target == num[l]) return l;
            if(num[mid] >= num[l]) {
                if( (target < num[l] || target > num[mid]) ) l = mid + 1;
                else r = mid - 1;
            } else {
                if(target >= num[l] || target < num[mid]) r = mid - 1;
                else l = mid + 1;
            } 
        }
        return -1;
    }
};
