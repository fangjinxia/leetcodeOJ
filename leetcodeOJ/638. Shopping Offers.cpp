class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        for (int i = n; i < 6; i++)
        {
            price.push_back(0);
            needs.push_back(0);
        }
        for (int i = special.size() - 1; i >= 0; i--)  // fill special to 6 items
        {
            int t = special[i][n];
            special[i][n] = 0;
            for (int j = n + 1; j < 7; j++)
                special[i].push_back(0);
            special[i][6] = t;
        }
        vector<int> temp(7);
        for (int i = 0; i < 6; i++)   //treat every item as a special offer only have itself with its price
        {
            for (int j = 0; j < 6; j++)
            if (j != i)
                temp[j] = 0;
            else
                temp[j] = 1;
            temp[6] = price[i];
            special.push_back(temp);
        }
        int dp[7][7][7][7][7][7], m = special.size();
        //memset(dp, INT_MAX, 7 * 7 * 7 * 7 * 7 * 7);      
           //I don't know why this memset useless, it just put every element to -1
        for (int j = 0; j < 7; j++)        // so I have initial it using loop
        {
            for (int k = 0; k < 7; k++)
            for (int p = 0; p < 7; p++)
            for (int q = 0; q < 7; q++)
            for (int r = 0; r < 7; r++)
            for (int s = 0; s < 7; s++)

                dp[j][k][p][q][r][s] = INT_MAX;
        }
        dp[0][0][0][0][0][0] = 0;
        for (int i = 0; i < m; i++)  // then it just a dynamic programming problem
        {
            for (int j = special[i][0]; j < 7; j++)
            for (int k = special[i][1]; k < 7; k++)
            for (int p = special[i][2]; p < 7; p++)
            for (int q = special[i][3]; q < 7; q++)
            for (int r = special[i][4]; r < 7; r++)
            for (int s = special[i][5]; s < 7; s++)
            {
                    int tt = dp[j-special[i][0]][k-special[i][1]][p-special[i][2]]
                                  [q-special[i][3]][r-special[i][4]][s-special[i][5]];
                    if (tt != INT_MAX)
                        dp[j][k][p][q][r][s] = min(dp[j][k][p][q][r][s], tt + special[i][6]);
            }
        }
        return dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }
};