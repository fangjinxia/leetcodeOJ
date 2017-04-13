class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> re(n, string(n, '.'));
        genNQueens(ans, re, 0, n);
        return ans;
    }
    
private:
    void genNQueens(vector<vector<string>>& ans, vector<string>& re, int srt, int end){
        if(srt == end){
            ans.push_back(re);
            return;
        }
        for(int i = 0; i < end; i++){
            if(isValid(re, srt, i, end)){
                re[srt][i] = 'Q';
                genNQueens(ans, re, srt+1, end);
                re[srt][i] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& re, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(re[i][col] == 'Q')
                return false;
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0 ; i--, j--){
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