class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i,num in enumerate(nums):
            
            if num in d.keys():
                return (i, d[num])
            else:
                d[target - num] = i
                
        return (0,0)
            
        
            
        