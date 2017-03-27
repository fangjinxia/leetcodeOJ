/*思路：每次将矩阵中心的元素与目标值比较，将矩阵分成四部分：左上、左下、右上、右下
 */
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
        int left = 0;
        int right = n-1;
        
        bool ans = search(matrix, target, up, down, left, right);
        
        return ans;
    }
private:
    bool search(vector<vector<int>>& matrix, int target, int up, int down, int left, int right){
        if(up == down && left == right)
            return (target == matrix[up][left]);
        if(up>down || left > right)
            return false;
        int midRow = up + (down-up)/2;
        int midCol = left + (right-left)/2;
        if(target == matrix[midRow][midCol]){
            return true;
        }
        else if(target < matrix[midRow][midCol]){
            return search(matrix, target, up, down, left, midCol-1) || search(matrix, target, up, midRow-1, midCol, right);
        }
        else{
            return search(matrix, target, up, midRow, midCol+1, right) || search(matrix, target, midRow+1, down, left, right);
        }
    }
};