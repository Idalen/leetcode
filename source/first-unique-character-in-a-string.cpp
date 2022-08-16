class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = {}
        
        res = -1
        char = 0
        
        for c in s:
            if c not in d.keys():
                d[c]=1
            else:
                d[c]+=1
                
        for key, val in d.items():
            if val == 1:
                char = key
                break
                
        if char == 0:
            return -1
        
        for i, c in enumerate(s):
            if char == c:
                return i
            
                