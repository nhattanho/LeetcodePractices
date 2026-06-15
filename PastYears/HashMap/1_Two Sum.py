#Approach 1: Two-pass Hash Table
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        #value -> key(hash)
        #index -> value(hash)
        for i in range(len(nums)):
            hashmap[nums[i]] = i;
            
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]]

#Approach 2: One-pass Hash Table
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        #value -> key(hash)
        #index -> value(hash)
            
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [hashmap[complement], i]
            else:
                hashmap[nums[i]] = i
