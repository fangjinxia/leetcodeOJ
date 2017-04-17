//¶¯Ì¬¹æ»®
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int arr[m][n];
        int ans = 0;
        for(int i = 0; i < m; i++){
            arr[i][0] = (matrix[i][0] == '0') ? 0 : 1;
            ans = max(ans, arr[i][0] * arr[i][0]);
        }
        for(int i = 0; i < n; i++){
            arr[0][i] = (matrix[0][i] == '0') ? 0 : 1;
            ans = max(ans, arr[0][i] * arr[0][i]);
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                arr[i][j] = (matrix[i][j] == '0') ? 0 : (min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1);
                ans = max(ans, arr[i][j] * arr[i][j]);
            }
        }
        
        return ans;
    }
};