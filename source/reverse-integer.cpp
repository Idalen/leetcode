#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        
        do{
            int algarism = x%10;
            x = (x-algarism)/10;
            if(y > INT_MAX/10 || y < INT_MIN/10 || (y == INT_MAX / 10 && algarism > 7) || (y == INT_MIN / 10 && algarism < -8)) return 0;
            y = 10*y + algarism;
        }while(x!=0);
        
        return y;
    }
};