class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words2_dict = {}
        results = []
        
        for word in words2:
            tmp = {}
            
            for c in word:
                if c in tmp.keys():
                    tmp[c] += 1
                else:
                    tmp[c] = 1
            
            for key in tmp.keys():
                if key in words2_dict.keys():
                    words2_dict[key] = max(words2_dict[key], tmp[key])
                else:
                    words2_dict[key] = tmp[key]
            
            
        
        for word in words1:
            
            tmp_d = words2_dict.copy()
            is_result = True
             
            for letter in word:
                if letter in tmp_d.keys():
                    tmp_d[letter] -= 1
                        
            for val in tmp_d.values():
                if val > 0:
                    is_result = False
                
            if is_result:
                results.append(word)
        
        return results
                    