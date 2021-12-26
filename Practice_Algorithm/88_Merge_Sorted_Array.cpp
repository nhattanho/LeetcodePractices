class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            for(int i = 0; i < n; i++) nums1[i] = nums2[i];
            return;
        };
        if(n == 0) return;
        vector<int>res;
        int left = 0, i = 0;
        for(i = 0; i < m; i++){
            if(nums1[i] < nums2[left]) res.push_back(nums1[i]);
            else {
                res.push_back(nums2[left]);
                left++;
                if(left >= n) break;
                i--;
            }
        }
        if(left >= n){
            for(int j = i; j < m; j++) res.push_back(nums1[j]);
        }else{
            for(int j = left; j < n; j++) res.push_back(nums2[j]);
        }
        
        for(int start = 0; start < res.size(); start++){
            nums1[start] = res[start];
        }
    }
};

/*More readable code*/
/*Time complexity 0(m+n), space 0(m+n)*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res;
        int left1 = 0, left2 = 0;
        while(left1 < m && left2 < n){
            if(nums1[left1] <= nums2[left2]){
                res.push_back(nums1[left1]);
                left1++;
            }else {
                res.push_back(nums2[left2]);
                left2++; 
            }
        }
        if(left1 >= m)
            for(int i = left2; i < n; i++) res.push_back(nums2[i]);
        else
            for(int i = left1; i < m; i++) res.push_back(nums1[i]);
        nums1 = res;
    }
};
