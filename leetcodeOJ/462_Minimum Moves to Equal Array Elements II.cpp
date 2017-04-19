class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                else if(i < j){
                    sum += nums[j] - nums[i];
                }
                else{
                    sum += nums[i] - nums[j];
                }
            }
            ans = min(ans, sum);
        }
        
        return ans;
    }
};