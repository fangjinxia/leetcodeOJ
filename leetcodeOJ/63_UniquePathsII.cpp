class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        int matrix[m][n] = {0};
        //≥ı ºªØ
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 0 && flag)
                matrix[0][i] = 1;
            else{
                flag = false;
                matrix[0][i] = 0;
            }
        }
        flag = true;
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 0 && flag)
                matrix[i][0] = 1;
            else{
                flag = false;
                matrix[i][0] = 0;
            }
        }
        //
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};