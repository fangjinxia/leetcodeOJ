//打印杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> re;
        if(numRows <= 0)
            return ans;
            
        re.push_back(1);
        ans.push_back(re);
        for(int i = 1; i < numRows; i++){
            vector<int> ss;
            ss.push_back(1);
            for(int j = 1; j < i; j++){//注意j的值与i有关
                ss.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ss.push_back(1);
            ans.push_back(ss);
            ss.clear();//清空容器
        }
        return ans;
    }
};