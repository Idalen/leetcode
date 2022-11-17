class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        a = {}
        b = {}
        
        for c in ransomNote:
            if c in a.keys():
                a[c] += 1
            else:
                a[c] = 1
                
        for c in magazine:
            if c in b.keys():
                b[c] += 1
            else:
                b[c] = 1
                
        for key in a.keys():
            if(key not in b.keys() or a[key] > b[key]):
                return False
        
        return True