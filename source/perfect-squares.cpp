#define MAXINT 10001
class Solution {
public:

    int rec(int n, int sum, int* mem){

        if(n<sum) return MAXINT;
        if(n == sum) return 0;
        if(mem[sum]!=-1) return mem[sum]+1;
        
        int res = MAXINT;
        for(int i=1; i<=sqrt(n); i++) res = min(res,rec(n, sum+i*i, mem));
        mem[sum] = res;

        return res+1;
    }
    int numSquares(int n) {
        int mem[n+1];

        for(int i=0; i<=n; i++) mem[i] = -1;

        return rec(n, 0, mem);
    }
};