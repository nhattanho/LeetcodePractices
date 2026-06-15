class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int l1 = 0, l2 = 0;
        int[] res = new int[m+n];
        Arrays.fill(res, 0);
        int count = 0;
        while(l1 < m && l2 < n){
            if(nums1[l1] <= nums2[l2]){
                res[count] = nums1[l1];
                l1++;
            }else{
                res[count] = nums2[l2];
                l2++;
            }
            count++;
        }
        if(l1 == m){
            while(l2 < n) res[count++] = nums2[l2++];
        }else if (l2 == n){
            while(l1 < m) res[count++] = nums1[l1++];
        }
        for(int i = 0; i < m+n; i++) nums1[i] = res[i];
    }
}
