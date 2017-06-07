class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{1,-1}, {1, 0}, {1, 1}, {0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                for(int d = 0; d < 8; d++){
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                        continue;
                    if(board[x][y] == 1 || board[x][y] == 2)
                        cnt++;
                }
                
                if(board[i][j] == 0 && cnt == 3)
                    board[i][j] = 3;
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3))
                    board[i][j] = 2;
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] %= 2;
            }
        }
    }
};