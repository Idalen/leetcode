class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
            d = {
                'a':".-",   
                'b':"-...",  
                'c':"-.-.",         
                "d":"-..",
                'e':".",
                'f':"..-.",
                'g':"--.",
                'h':"....",
                'i':"..",
                'j':".---",
                'k':"-.-",
                'l':".-..",
                'm':"--",
                'n':"-.",
                'o':"---",
                'p':".--.",
                'q':"--.-",
                'r':".-.",
                's':"...",
                't':"-",
                'u':"..-",
                'v':"...-",
                'w':".--",
                'x':"-..-",
                'y':"-.--",
                'z':"--.."
            }
            
            morse = []
            
            for word in words:
                string = ""
                for c in word:
                    string+=d[c]
                morse.append(string)
                
            return len(set(morse))