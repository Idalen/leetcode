#define size 45

class Solution {
public:
    int dp[size];

    // int rec(int sum, int count){
        
    //     cout << sum << " "<< count << endl;
    //     if(sum <= 0) return sum == 0;

    //     if(dp[sum] != 0) return dp[sum];

    //     count+=rec(sum-1, count);
    //     count+=rec(sum-2, count);

    //     dp[sum] = count;

    //     return count;
    // }
    
    int climbStairs(int n) {
        
        dp[0] = 1;
        dp[1] = 2;

        for(int i=2;i<n;i++) dp[i]=dp[i-1]+dp[i-2];
        return dp[n-1];
    }
};


