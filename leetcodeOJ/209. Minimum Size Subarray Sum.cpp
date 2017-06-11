class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < s){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = 0;
            for(int j = i; j < nums.size(); ++j){
                tmp += nums[j];
                if(tmp >= s){
                    ans = min(ans, j-i+1);
                    break;
                }
                    
            }
        }
        return ans;
        
    }
};


//比较好的方法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, minlen = INT_MAX;
        while (right < n) {
            do sum += nums[right++];
            while (right < n && sum < s);
            while (left < right && sum - nums[left] >= s)
                sum -= nums[left++];
            if (sum >= s) minlen = min(minlen, right - left);
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};