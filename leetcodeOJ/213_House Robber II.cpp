class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        int pre1 = 0;
        int cur1 = 0;
        for(int i = 0; i < n-1; i++){
            int temp = pre1;
            pre1 = cur1;
            cur1 = max(pre1, temp+nums[i]);
        }
        
        int pre2 = 0;
        int cur2 = 0;
        for(int i = 1; i < n; i++){
            int temp = pre2;
            pre2 = cur2;
            cur2 = max(pre2, temp+nums[i]);
        }
        
        return max(cur1, cur2);
    }
};