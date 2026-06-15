/* Time complexity O(logn), Space O(1) */
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if(isBadVersion(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
