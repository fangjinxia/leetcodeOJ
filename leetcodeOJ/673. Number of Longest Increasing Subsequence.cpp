/*
 * cnt[k] is total number of longest subsequence ending with nums[k];
 * len[k] is the length of longest subsequence ending with nums[k];
 *
 * len[k+1] = max(len[k+1], len[i]+1) for all i <= k and nums[i] < nums[k+1];
 * cnt[k+1] = sum(cnt[i]) for all i <= k and nums[i] < nums[k+1] and len[i] = len[k+1]-1;
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        
        int maxlen = 1;
        vector<int> cnt(n, 1), len(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = i-1; j >= 0; --j){
                if(nums[i] > nums[j]){
                    if(len[i] < len[j]+1){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(len[i] == len[j]+1){
                        cnt[i] += cnt[j];
                    }
                    
                }                
            }
            
            maxlen = max(maxlen, len[i]);
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(len[i] == maxlen){
                res += cnt[i];
            }
        }
        return res;
    }
};