class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int lo = 0;
        int hi = nums.size()-1;
        return genPairs(nums, lo, hi);
        
    }
    
private:
    int genPairs(vector<int>& nums, int lo, int hi){
        if(lo >= hi)
            return 0;
        int mid = lo + (hi-lo)/2;
        int left = genPairs(nums, lo, mid);
        int right = genPairs(nums, mid+1, hi);
        int cnt = 0;
        for(int i = lo, j = mid+1; i <= mid; i++){
            while(j<=hi && ((long long)nums[i] > 2*(long long)nums[j])){
                j++;
            }
            cnt += j-(mid+1);
        }
        sort(nums.begin()+lo, nums.begin()+hi+1);
        return cnt+left+right;
    }
};