//思路：典型的动态规划题
//递推式：ans[n] = ans[n-1] + ans[n-2]
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)
            return 1;
        int ans[n+1] = {0};
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2; i < n+1; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};