import numpy as np
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        maximun = 0
        d = {}
        count = 0
        for i in range(len(nums)):
            count+= 1 if nums[i] else -1
            if count == 0:
                maximun = 1+i
            elif count in d:
                maximun = max(maximun, i-d[count])
            else:
                d[count] = i
            
        return maximun
                