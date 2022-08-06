class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie + 1;
        int pigs = 0;
        int aux=1;
        
        while(aux<buckets){
            aux*=t;
            pigs++;
        }
        
        return pigs;
    }
};