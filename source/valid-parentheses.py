class Solution:
    def isValid(self, s: str) -> bool:
        d = { '(':')', '[':']', '{':'}'}
        l = []
        for c in s:
            if c in d.keys():
                l.append(c)
            elif (len(l)>0 and c == d[l[-1]]):
                l.pop(-1)
            else:
                return False
        return True if len(l) == 0 else False
                    