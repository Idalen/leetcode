class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        d = {}
        
        for i in arr:
            if i in d.keys():
                d[i] += 1
            else:
                d[i] = 1
                
        d = dict(sorted(d.items(), key=lambda x:x[1], reverse=True))
        
        acc=0
        res=0
        for key, val in d.items():
            acc+=val
            res+=1
            if acc >= len(arr)//2:
                break
                
        return res