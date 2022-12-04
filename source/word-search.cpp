class Solution {
public:
    // void print(vector<vector<int>>& matrix){
    //     for(auto v : matrix){
    //         for(auto x:v){
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }

    //     cout << endl;
    // }

    void rotate(vector<vector<int>>& matrix) {
        
        int tmp, size=matrix.size();
        for(int i=0; i<size/2; i++){
            for(int j=i; j<size-i-1; j++){
                
                tmp = matrix[size-j-1][i];
                matrix[size-j-1][i] = matrix[size-i-1][size-j-1]; 
                matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
                matrix[j][size-1-i] = matrix[i][j];
                matrix[i][j] = tmp;

                //print(matrix);
            }
        }
    }
};