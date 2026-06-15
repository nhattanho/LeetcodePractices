/*
[0] [1] [2] [3] [4] [5]
 1   2   3   4   5   6 => num[0] < num[mid]
 2   3   4   5   6   1 => num[0] < num[mid]
 3   4   5   6   1   2 => num[0] < num[mid]
 4   5   6   1   2   3 => num[0] < num[mid]
 ==> the left part is sorted
 
 5   6   1   2   3   4 => num[0] > num[mid]
 6   1   2   3   4   5 => num[0] > num[mid]
==> the right part is sorted
*/
class Solution {
public:
    int search(vector<int>& num, int target) {
        int l = 0, r = num.size()-1, mid = 0;
        while(l <= r){
            mid = r - (r-l)/2;
            if(num[mid] == target)  return mid;
            
            if(num[l] <= num[mid]){ /*left part is sorted*/
                if(target >= num[l] && target < num[mid]) r = mid-1;
                else l = mid+1;
            }else{ /*right part is sorted*/
                if(target > num[mid] && target <= num[r])
                    l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};

/*Recursive function*/
int findPos(vector<int>&num, int target, int l, int r){
    if(l>r) return -1;
    int mid = r - (r-l)/2;
    if(num[mid] == target)  return mid;

    if(num[l] <= num[mid]){ /*left part is sorted*/
        if(target >= num[l] && target < num[mid])
            return findPos(num, target, l, mid-1);
        else return findPos(num, target, mid+1, r);
    }else{ /*right part is sorted*/
        if(target > num[mid] && target <= num[r])
            return findPos(num, target, mid+1, r);
        else return findPos(num, target, l, mid-1);
    }
}


class Solution {
public:
    int search(vector<int>& num, int target) {
        int l = 0, r = num.size()-1;  
        return findPos(num, target, l, r);
    }
};
