class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 2)
            return nums;
        
        vector<int> count(n, 0), pre(n, 0);
        int max = 0, idx = -1;
        for(int i = 0; i < n; i++){
            count[i] = 1;
            pre[i] = -1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(count[j]+1 > count[i]){
                        count[i] = count[j]+1;
                        pre[i] = j;
                    }
                }
            }
            
            if(count[i] > max){
                max = count[i];
                idx = i;
            }
        }
        vector<int> v(0);
        while(idx != -1){
            v.push_back(nums[idx]);
            idx = pre[idx];
        }
        return v;
    }
};