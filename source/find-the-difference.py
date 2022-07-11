class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ds = {}
        for c in s:
            if c in ds.keys():
                ds[c] +=1
            else:
                ds[c] = 1
                
        for c in t:
            if c in ds.keys():
                ds[c] -=  1
                if(ds[c] < 0):
                    return c
            else:
                return c
        
        