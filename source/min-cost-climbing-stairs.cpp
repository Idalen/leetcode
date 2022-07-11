using namespace std;
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int mem[cost.size()+1];
        mem[0]=0;
        
        
        for(int i = 0; i<cost.size(); i++){
            mem[i+1] = cost[i] + min(mem[i], mem[max(i-1,0)]);
        }
        
        return min(mem[cost.size()], mem[cost.size()-1]);
    }
};