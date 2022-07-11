class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        g = {}
        for edge in edges:
            if edge[0] not in g.keys():
                g[edge[0]] = []
            g[edge[0]].append(edge[1])
            if edge[1] not in g.keys():
                g[edge[1]] = []
            g[edge[1]].append(edge[0])
        maximun = 0
        node =  None
        for k, i in g.items():
            if len(i) > maximun:
                maximun=len(i)
                key = k 
            
        return key