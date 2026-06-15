/* Time complexity has to be O(N), N is the length of string
Because, for example, at the first time, we move a time at a charaters,
then we need to move the left pointer to delete the leftmost <=> moving 
approximately a times. Then we continue moving b times ==> the left pointer 
also move to b time, and so on ==> the time: a+a+b+b+.... = 2(a+b+....) = 2N
==> O(2N) === O (N) */


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        
        int len = s.length();
        int l = 0, count = 0, maxL = 1;
        unordered_map<char, int> m;
        
        for(int i=0; i < len; i++){
            char x = s[i];
            if(m[x] == 0) count++;
            m[x]++;
            
            if(count > k) maxL = max(maxL, i-l);
            
            while(count > k){
                x = s[l];
                m[x]--;
                l++;
                if(m[x] == 0) count--;
            }
        }
        maxL = max(maxL, len-l); // don't miss the last one
        return maxL;
    }
};
