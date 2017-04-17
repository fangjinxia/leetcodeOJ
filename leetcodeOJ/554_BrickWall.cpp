//各行内宽度逐个累加，行首从0开始，排序找到中间值出现最多的次数，墙高相减即可
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();//m为墙高
        if(m == 0)  
            return 0;
        int sum = accumulate(wall[0].begin(), wall[0].end(), 0);
        map<int, int> v;
        int ans = 0;
        for(int i = 0; i < m; i++){
            int height = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                height += wall[i][j];
                v[height]++;
                ans = max(ans, v[height]);
            }
        }
        return m-ans;
    }
};