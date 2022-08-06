class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        while( !(p%2 || q%2) ){
            p/=2;
            q/=2;
        }
        
        // 1, 0 -> 2
        // 3, 1 -> 0
        // 2 ,1 -> 1
        
        return 1 - p%2 + q%2;
    }
};