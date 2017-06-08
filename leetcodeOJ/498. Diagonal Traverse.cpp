class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0 || matrix[0].size()==0)
            return ans;
        
        bool down = false, up = true;
        //ans.push_back(matrix[0][0]);
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        while(ans.size() < m*n){
            ans.push_back(matrix[i][j]);
            if(down){
                if(i == m-1){
                    j++;
                    up = true;
                    down = false;
                }
                else if(j == 0){
                    i++;
                    up = true;
                    down = false;
                }
                else{
                    i++;
                    j--;
                }
            }
            else if(up){
                if(j == n-1){
                    i++;
                    up = false;
                    down = true;
                }
                else if(i == 0){
                    j++;
                    up = false;
                    down = true;
                }
                else{
                    i--;
                    j++;
                }
            }
            
        }
        return ans;
    }
};