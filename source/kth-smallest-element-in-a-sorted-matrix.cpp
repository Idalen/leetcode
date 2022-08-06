class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ordered;
        
        while(ordered.size() < k){
            
            int minimum = INT_MAX;
            int row;
            for(int i=0;i < matrix.size(); i++){

                if(matrix[i].empty())
                    continue;

                if(matrix[i].front() <= minimum){
                    minimum = matrix[i].front();
                    row = i;
                }

            }

            ordered.push_back(minimum);
            matrix[row].erase(matrix[row].begin());
        }
        
        return ordered[k-1];
    }
};