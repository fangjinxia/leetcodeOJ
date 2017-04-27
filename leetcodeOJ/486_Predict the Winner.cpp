/*
Helper function simulate this process. In each round:
if e==s, there is no choice but have to select nums[s]
otherwise, this current player has 2 options:
--> nums[s]-helper(nums,s+1,e): this player select the front item, leaving the other player a choice from s+1 to e
--> nums[e]-helper(nums,s,e-1): this player select the tail item, leaving the other player a choice from s to e-1
Then take the max of these two options as this player's selection, return it.
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) 
            return true;
        return (genPred(nums, 0, n-1) >= 0);
    }
    
private:
    int genPred(vector<int>& nums, int srt, int end){
       return srt == end ? nums[end] : max(nums[end] - genPred(nums, srt, end-1), nums[srt] - genPred(nums, srt+1, end));
    }
};


///<利用动态规划
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
            }
        }
        return dp[0][n-1] >= 0; // player1 get more score points than player2
    }
};