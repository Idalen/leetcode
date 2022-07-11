class Solution {
public:
    int fib(int n) {
        vector<int> v = {0, 1};
        for(int i=1; i<n; i++)
            v.push_back(v[i-1] + v[i]);
        
        return v.at(n);
    }
};