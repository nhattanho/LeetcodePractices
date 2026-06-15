class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        gr = defaultdict(list)
        
        #Time complexity 0(m) with m is the length of path
        for key, value in paths:
            gr[key].append(value)
            gr[value].append(key)
         
        #list saved the used flower of garden
        #ex: ans[0] ==> save the flower used in garden 1
        ans = [0]*n
        
        #Time complexity: 3n
        for i in range(1,n+1):
            used = [1,2,3,4]
            #each gardern has maximum 3 child/adjacent
            for garden in gr[i]:
                #if the child garden has used the flower, the parent has to use different one
                if ans[garden-1] != 0 and ans[garden-1] in used:
                    #remove all flowers used by children garden
                    used.remove(ans[garden-1])
            #Out of the checking, all child garden, used list will save the possible flowers
            ans[i-1] = used[0]
        return ans
