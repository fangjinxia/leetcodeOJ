//DFS
//思想：只有边界上'O'的位置组成的片区不会被'X'包围。
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return ;
        
        swap(bd, board);
        m = bd.size();
        n = bd[0].size();
        
        for(int i = 0; i < n; ++i){
            if(bd[0][i] == 'O')
                dfs(0, i);
            if(bd[m-1][i] == 'O')
                dfs(m-1, i);
        }
        
        for(int i = 0; i < m; ++i){
            if(bd[i][0] == 'O')
                dfs(i, 0);
            if(bd[i][n-1] == 'O')
                dfs(i, n-1);
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(bd[i][j] == '*')
                    bd[i][j] = 'O';
                else if(bd[i][j] == 'O')
                    bd[i][j] = 'X';
            }
        }
        
        swap(bd, board);
    }
    
    void dfs(int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || bd[x][y] != 'O')
            return ;
        
        bd[x][y] = '*';
        if(x > 1 && bd[x-1][y] == 'O')
            dfs(x-1, y);
        if(x < m-1 && bd[x+1][y] == 'O')
            dfs(x+1, y);
        if(y > 1 && bd[x][y-1] == 'O')
            dfs(x, y-1);
        if(y < n-1 && bd[x][y+1] == 'O')
            dfs(x, y+1);
    }
    
private:
    int m, n;
    vector<vector<char>> bd;
};