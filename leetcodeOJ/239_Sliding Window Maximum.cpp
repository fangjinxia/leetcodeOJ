class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        for(int i = 0; i <= n-k; i++){
            ans.push_back(genMax(nums, i, k));
        }
        return ans;
    }
    
private:
    int genMax(vector<int>& nums, int srt, int k){
        int m = nums[srt];
        for(int i = 1; i < k; i++){
            m = max(m, nums[i+srt]);
        }
        return m;
    }
};