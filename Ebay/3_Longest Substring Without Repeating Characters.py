class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        map = {}
        res = 0
        
        for i in range(len(s)):
            if s[i] not in map: # Means the current character has not been existed on the current substring 
                map[s[i]] = 1   # Add the unique character into substring     
            else: # Duplicated character
                while map[s[i]] != 0:
                    map[s[left]] -= 1
                    left += 1
                map[s[i]] = 1
            res = max(res, i-left+1)
        return res
