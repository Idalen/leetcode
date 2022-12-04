#define SIZE 9
class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<char, int> map;

        for(int i=0; i<SIZE; i++){
            
            map.clear();
            for(int j=0;j<SIZE;j++){
                if(board[i][j]!='.'){
                    map[board[i][j]]++;
                    if(map[board[i][j]] == 2) return false;
                }
            }

            map.clear();
            for(int j=0; j<SIZE; j++){
                if(board[j][i]!='.'){
                    map[board[j][i]]++;
                    if(map[board[j][i]] == 2) return false;
                }
            }

            map.clear();
            for(int j=0; j<SIZE; j++){
                if(board[3*(i/3)+j/3][3*(i%3)+j%3]!='.'){
                    map[board[3*(i/3)+j/3][3*(i%3)+j%3]]++;
                    if(map[board[3*(i/3)+j/3][3*(i%3)+j%3]] == 2) return false;
                }
            }

        }

        return true;
    }
};