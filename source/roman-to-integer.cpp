class Solution {
public:
    int romanToInt(string s) {
        int n=0;
        char last = '\0';
        for(auto c:s){
            switch (c){
                case 'M':
                    n+=1000;
                    if(last == 'C')
                        n-=200;
                    break;
                case 'D':
                    n+=500;
                    if(last == 'C')
                        n-=200;
                    break;
                case 'C':
                    n+=100;
                    if(last == 'X')
                        n-=20;
                    break;
                case 'L':
                    n+=50;
                    if(last == 'X')
                        n-=20;
                    break;
                case 'X':
                    n+=10;
                    if(last == 'I')
                        n-=2;
                    break;
                case 'V':
                    n+=5;
                    if(last == 'I')
                        n-=2;
                    break;
                case 'I':
                    n+=1;
                    break;
            }
            last = c;
        }   
    return n;
    }
    
};