//动态规划
//思路：对空间复杂度有要求，申请一个n大小的数组，初始化为第n-1行的元素，
//本题可用动态规划来解，从下往上处理，第i行第j列元素的值为（min（第i+1行第j列元素，第i+1行第j+1列元素）+  第i行第j列元素）
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans[n];
        for(int i = 0; i < n; i++){
            ans[i] = triangle[n-1][i];//初始化为最后一列
        }
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1-i; j++){
                ans[j] = triangle[n-2-i][j] + min(ans[j], ans[j+1]);
            }
        }
        return ans[0];
    }
};