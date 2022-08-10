class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
       
        //dp[i] = sum(dp[j] * dp[i / j])
        long res=0, mod = pow(10, 9) + 7;
        
        sort(arr.begin(), arr.end());
        unordered_map<int, long> mem;
        
        for(int i=0;i<arr.size();i++){
            mem[arr[i]] = 1;
            for(int j=0;j<i;++j)
                if(arr[i]%arr[j]==0) mem[arr[i]] = (mem[arr[i]]+mem[arr[j]]*mem[arr[i]/arr[j]])%mod;
            res=(res+mem[arr[i]])%mod;
            cout << mem[arr[i]] << " ";
        }
        
        return res;
        
    }
};