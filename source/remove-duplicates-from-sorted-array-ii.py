class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        last_n = nums[0]
        count = 0
        i = 0
        while(i<len(nums)):
            if(nums[i] == last_n):
                count+=1
                if(count > 2):
                    nums.remove(last_n)
                    i-=1
            else:
                last_n = nums[i]
                count = 1
            i+=1
        return i