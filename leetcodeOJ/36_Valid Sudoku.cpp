class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //判断每一行
        for(int i = 0; i < 9; i++){
            vector<int> v(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    v[num]++;
                    if(v[num] > 1)
                        return false;
                }
            }
        }
        //判断每一列
        for(int i = 0; i < 9; i++){
            vector<int> v(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    int num = board[j][i] - '0';
                    v[num]++;
                    if(v[num] > 1)
                        return false;
                }
            }
        }
        //判断每个方格
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                bool ans = isValid(board, 3*i, 3*j, 3);
                if(!ans)
                    return false;
            }
        }
        return true;
    }
private:
    bool isValid(vector<vector<char>>& board, int row, int col, int k){
        vector<int> v(10, 0);
        for(int i = row; i < row+k; i++){
            for(int j = col; j < col+k; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(v[num] == 1)
                        return false;
                    v[num] = 1;
                }
            }
        }
        return true;
    }
};