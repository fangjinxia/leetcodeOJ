class Solution {
public:
    const int dir[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if(board[click[0]][click[1]] == 'E'){
            int tmp = 0;
            for(int i = 0; i < 8; ++i){
                int x = click[0] + dir[i][0];
                int y = click[1] + dir[i][1];
                if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                    continue;
                if(board[x][y] == 'M')
                    ++tmp;
            }    
            if(tmp == 0){
                board[click[0]][click[1]] = 'B';
                for(int i = 0; i < 8; ++i){
                    int x = click[0] + dir[i][0];
                    int y = click[1] + dir[i][1];
                    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                        continue;
                    vector<int> re(0);
                    re.push_back(x);
                    re.push_back(y);
                    updateBoard(board, re);
                }
            }
            else if(tmp != 0)
                board[click[0]][click[1]] = tmp+'0';
            
        }
        return board;
    }
};