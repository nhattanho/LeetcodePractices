/* Time complexity O(m*n), Space O(max(m,n)), m is a.size and n is b.size */
class Solution {
public:
    int getRes(vector<int> a, vector<int>b){
        int count = 0;
        map<int,int>map;
        long temp1, temp2;
        for(int i = 0; i < a.size(); i++){
            temp1 = (long)a[i]*(long)a[i]; 
            for(int j = 0; j < b.size(); j++){
                if(temp1 % b[j] == 0) {
                    temp2 = temp1/b[j];
                    if(map[temp2] != 0) count += map[temp2]; // example: 4^2 = 16 and 2 8 2 2 8
                    map[b[j]]++;
                }
            }
            map.clear();
        }
        return count;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return getRes(nums1, nums2) + getRes(nums2, nums1);
    }
};
