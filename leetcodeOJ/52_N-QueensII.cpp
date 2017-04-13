class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> re(n, string(n, '.'));
        genNQueens(re, ans, 0, n);
        return ans;
    }
    
private:
    void genNQueens(vector<string>& re, int &ans, int row, int n){
        if(row == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(isValid(re, row, i, n)){
                re[row][i] = 'Q';
                genNQueens(re, ans, row+1, n);
                re[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& re, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(re[i][col] == 'Q')
                return false;
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(re[i][j] == 'Q')
                return false;
        }
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if(re[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
};