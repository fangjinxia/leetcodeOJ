class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0)
            return ans;
        int n = matrix[0].size();
        int num = m*n;
        int left = 0, right = n-1; 
        int up = 0, down = m-1;
    
        while(left <= right && up <= down){
            int i = up;
            for(int j = left; j <= right; j++){
                if(ans.size() == num)
                    return ans;
                ans.push_back(matrix[i][j]);
            }
            up++;
            
            i = right;
            for(int j = up; j <= down; j++){
                if(ans.size() == num)
                    return ans;
                ans.push_back(matrix[j][i]);    
            }
            right--;
            
            i = down;
            for(int j = right; j >= left; j--){
                if(ans.size() == num)
                    return ans;
                ans.push_back(matrix[i][j]);    
            }
            down--;
            
            i = left;
            for(int j = down; j >= up; j--){
                if(ans.size() == num)
                    return ans;
                ans.push_back(matrix[j][i]);    
            }
            left++;
            
        }
        return ans;
    }
};



/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0)
            return ans;
        int n = matrix[0].size();
        int num = m*n;
        int left = 0, right = n-1; 
        int up = 0, down = m-1;
    
        while(left <= right && up <= down){
            int i = up;
            for(int j = left; j <= right; j++){
                // if(ans.size() == num)
                //     return ans;
                ans.push_back(matrix[i][j]);
            }
            up++;
            if(up>down)
                break;
                
            i = right;
            for(int j = up; j <= down; j++){
                // if(ans.size() == num)
                //     return ans;
                ans.push_back(matrix[j][i]);    
            }
            right--;
            if(left>right)
                break;
            
            i = down;
            for(int j = right; j >= left; j--){
                // if(ans.size() == num)
                //     return ans;
                ans.push_back(matrix[i][j]);    
            }
            down--;
            if(up>down)
                break;
            
            i = left;
            for(int j = down; j >= up; j--){
                // if(ans.size() == num)
                //     return ans;
                ans.push_back(matrix[j][i]);    
            }
            left++;
            if(left>right)
                break;
            
        }
        return ans;
    }
};

*/