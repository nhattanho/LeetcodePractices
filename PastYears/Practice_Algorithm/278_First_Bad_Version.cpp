class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid = l + (r-l)/2;
        while(l<r){
            mid = l + (r-l)/2;
            if(!isBadVersion(mid)) l = mid+1; /*current is good -> need to check from the right side by increase left*/
            else r = mid;/*try to find the first bad version from the left, but the current mid maybe the first bad, then r = mid*/
        }
        /*
        if(l == r) mid = l + (r-l)/2;
        return mid;
        */
        return l;/*l == r ==> has to be the first bad, since could not find any bad version from the left side*/
    }
};
