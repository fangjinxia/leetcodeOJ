class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        if(nums.size() < 3)
            return 0;
        
        for(int i = 0; i < nums.size()-2; ++i){
            int lo = i+1; 
            int hi =  nums.size() - 1;
            while(lo < hi){
                int tmp = lo;
                while(tmp < hi && nums[i]+nums[tmp] <= nums[hi]){
                    ++tmp;
                }
                res += hi-tmp;
                --hi;
            }
        }
        
        return res;
    }
};