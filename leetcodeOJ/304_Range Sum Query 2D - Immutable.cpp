class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        accu = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for(int i = 0; i < matrix.size(); i++){
            accu[i][0] = 0;
            for(int j = 1; j <= matrix[0].size(); j++){
                accu[i][j] = accu[i][j-1] + matrix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int k = 0;
        for(int i = row1; i <= row2; i++){
            k += accu[i][col2+1] - accu[i][col1];
        }
        return k;
    }
    
private:
    vector<vector<int>> accu;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */