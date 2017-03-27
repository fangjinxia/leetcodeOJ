//思路：二分查找,先确定在哪行，再确定在哪列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)  
            return false;
        int n = matrix[0].size();
        if(n == 0)  
            return false;
            
        int up = 0;
        int down = m-1;
        int midRow = 0;
        while(up <= down){
            midRow = up + (down-up)/2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1])
                break;
            if(target < matrix[midRow][0])
                down = midRow-1;
            else if(target > matrix[midRow][n-1])
                up = midRow+1;
        }
        int left = 0;
        int right = n-1;
        int midCol = 0;
        while(left <= right){
            midCol = left + (right-left)/2;
            if(target == matrix[midRow][midCol])
                return true;
            else if(target > matrix[midRow][midCol])
                left = midCol+1;
            else
                right = midCol-1;
        }
        return false;
    }
};