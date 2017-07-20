class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(); 
        if(n == 0)
            return nums;
        int m = nums[0].size();
        if(r*c != n*m)
            return nums;
        
        vector<vector<int>> v(r, vector<int>(c, 0));
        int x = 0;
        int y = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                v[i][j] = nums[x][y];
                x = (y == m-1) ? (x+1) : x;
                y = (y == m-1) ? 0 : (y+1);
            }
        }
        return v;
    }
};