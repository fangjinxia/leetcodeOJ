class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            int cnt = 0;
            for(int k = i; nums[k] >= 0; cnt++){
                int nextnum = nums[k];
                nums[k] = -1;
                k = nextnum;
            }
            
            ans = max(cnt, ans);
        }
        return ans;
    }
};