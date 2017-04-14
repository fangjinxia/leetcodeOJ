class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //ÏÈ¸ønumsÅÅĞò
        if(k < 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> newArr(n);
        for(int i = 0; i < n; i++)
            newArr[i] = nums[i]+k;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            for(int j = 0; j < n; j++){
                if(nums[i] == newArr[j] && i != j){
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};