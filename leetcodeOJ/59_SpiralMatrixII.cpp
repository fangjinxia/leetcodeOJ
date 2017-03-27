class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int num = 1;
        int left = 0;
        int right = n-1;
        int up = 0; 
        int down = n-1;
        while(left <= right && up <= down){
            int i = up;
            for(int j = left; j <= right; j++){
                ans[i][j] = num;
                num++;
            }
            up++;
            if(up>down)
                break;
                
            i = right;
            for(int j = up; j <= down; j++){
                ans[j][i] = num;    
                num++;
            }
            right--;
            if(left>right)
                break;
            
            i = down;
            for(int j = right; j >= left; j--){
                ans[i][j] = num;
                num++;
            }
            down--;
            if(up>down)
                break;
            
            i = left;
            for(int j = down; j >= up; j--){
                ans[j][i] = num;    
                num++;
            }
            left++;
            if(left>right)
                break;
            
        }
        return ans;
    }
};