/*Time and Space complexity O(N), N is the length of nums*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for(auto x:nums)
            fre[x]++;
        int res = 0;
        for(auto x:nums){
            if(fre[x]!=0){
                int temp = k-x;
                if(fre[temp]!= 0){
                    fre[x]--;
                    fre[temp]--;
                    if(fre[temp]>=0) res++;
                    else { /*Check for special case [3,1,3,4,3], k = 6*/
                        // fre[temp]++;
                        // fre[x]++;
                        fre[temp] = 0;
                    }
                }
            }
        }
        return res;
    }
};
