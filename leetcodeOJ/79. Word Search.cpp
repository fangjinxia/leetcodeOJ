class Solution {
private:
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n == 0)
            return false;
        int m = board[0].size();
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] != word[0])
                    continue;
                vector<vector<int>> visited(n, vector<int>(m, 0)); 
                visited[i][j] = 1;
                if(backTrace(board, visited, word, i, j, 1))
                    return true;
                
            }
        }
        return false;
    }
    
    bool backTrace(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int x, int y, int k){
        if(word.length() == k)
            return true;
            
        for(int i = 0; i < 4; ++i){
            int tmp_x = x + dir[i][0];
            int tmp_y = y + dir[i][1];
            if(tmp_x < 0 || tmp_x >= board.size() || tmp_y < 0 || tmp_y >= board[0].size() || visited[tmp_x][tmp_y] == 1)
                continue;
            
            if(board[tmp_x][tmp_y] == word[k]){
                visited[tmp_x][tmp_y] = 1;
                if(backTrace(board, visited, word, tmp_x, tmp_y, k+1))
                    return true;
                visited[tmp_x][tmp_y] = 0;
            }
        }
        return false;
    }
};