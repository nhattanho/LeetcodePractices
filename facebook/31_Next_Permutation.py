'''
Example: 
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3 
......
==> just look like we need to find a larger number than a original number
==> check from the right to the left
so if a[i] >= a[i+1] ==> we need move to the left to check for the left-pair
else if a[i] < a[i+1] ==> we need to replace a[i] by the minimum of all numbers that
larger than a[i]
Example:
1 5 8 4 7 6 5 4 3 2
As we can see, 7 > 6 > 5 > 4 > 3 > 2
However, 4 < 7, we need to replace 4 by the larger number in (7 6 5) and min(7 6 5) = 5
(We could not replace 4 by 4 - duplicated since it would not get the next larger)
==> let:
j = i-1 ==> a[j] = 4
start = i+1 ==> a[start] = 6

Run start from start->len, whenever having a[j] >= a[start]
==> replace a[j] by a[start-1], and sort the numbers from i->len
'''

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        l = len(nums)
        if l == 1: return nums
        
        for i in range(l-1, -1, -1):
            if nums[i] > nums[i-1]:
                j = i-1
                start = i+1
                
                while(start <= l):
                    if start == l or (nums[j] >= nums[start]):
                        nums[j], nums[start-1] = nums[start-1], nums[j]
                        nums[i:l] = nums[i:l][::-1]
                        return nums
                    else:
                        start += 1
      
            elif nums[i-1] >= nums[i]:
                if i == 1: 
                    return nums.reverse()
            
        return nums
