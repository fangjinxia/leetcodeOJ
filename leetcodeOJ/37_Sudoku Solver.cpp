class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        genSolver(board, 0);
    }
    
private:
    bool genSolver(vector<vector<char>>& board, int pos){
        if(pos == 81){
            return true;
        }
        int x = pos/9;
        int y = pos%9;
        if(board[x][y] != '.')
            return genSolver(board, pos+1);
        for(int i = 1; i <= 9; i++){
            char tmp = i+'0';
            if(isValid(board, tmp, x, y)){
                board[x][y] = tmp;
                if(genSolver(board, pos+1))
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, char c, int x, int y){
        for(int i = 0; i < 9; i++){
            if(board[i][y] == c)
                return false;
        }
        for(int i = 0; i < 9; i++){
            if(board[x][i] == c)
                return false;
        }
        int kx = 3*(x/3);
        int ky = 3*(y/3);
        for(int i = kx; i < kx+3; i++){
            for(int j = ky; j < ky+3; j++){
                if(board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
};