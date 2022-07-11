class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        acc = 0
        d = {}
        for i in nums:
            if i in d.keys():
                d[i]+=1
            else:
                d[i] = 0
        for key in d.keys():
            if(k==0):
                if d[key] > 0:
                    acc+=1
            elif key+k in d.keys():
                acc+=1 
        return acc 