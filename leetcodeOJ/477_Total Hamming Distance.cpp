class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(n == 0 || n == 1)
            return 0;
        for(int i = 0; i < 32; i++){
            int bitCnt = 0;
            for(int j = 0; j < n; j++){
                if((nums[j]>>i) & 1 == 1)
                    bitCnt++;
            }
            cnt += bitCnt*(n-bitCnt);
        }
        
        return cnt;
    }
};