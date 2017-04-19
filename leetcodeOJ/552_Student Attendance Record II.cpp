//动态规划
/**
 * dp[i]the number of all possible attendance (without 'A') records with length i :
    end with "P": dp[i-1]
    end with "PL": dp[i-2]
    end with "PLL": dp[i-3]
    end with "LLL": is not allowed
    so dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    
    the number of all possible attendance (with 'A') records with length n:
    ∑dp[i] *dp[n-1-i] i = 0,1,...,n-1
    
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    int checkRecord(int n) {
        long long M = 1000000007;
        // if(n == 1)
        //     return 3;
        // if(n == 0)
        //     return 1;
        vector<long long> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        //没有A
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % M;
        }
        //存在A
        long long ans = dp[n];
        for(int i = 0; i < n; i++){
            if(i == 0)
                ans += dp[n-1-i] % M;
            else if(i == n-1)
                ans += dp[i] % M;
            else
                ans += (dp[i] * dp[n-1-i]) % M;
            ans %= M;
        }
        return (int)ans;
    }
};