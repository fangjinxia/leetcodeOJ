class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex);
        for(int i = 0; i < rowIndex; i++)
            ans[i] = 0;
        if(rowIndex < 0)
            return ans;
            
        ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            ans[i] = 1;
            for(int j = i-1; j > 0; j--)
                ans[j] += ans[j-1];
            ans[0] = 1;
        }
        return ans;
    }
};