class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        //在grid外边一圈加0
        vector<int> v(m+2, 0);
        grid.insert(grid.begin(), v);
        for(int i = 1; i <= n; i++){
            grid[i].insert(grid[i].begin(), 0);
            grid[i].push_back(0);
        }
        grid.push_back(v);
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grid[i][j] == 1){
                    if(grid[i-1][j] == 0)
                        ans++;
                    if(grid[i+1][j] == 0)
                        ans++;
                    if(grid[i][j-1] == 0)
                        ans++;
                    if(grid[i][j+1] == 0)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};