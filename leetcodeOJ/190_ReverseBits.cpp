class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int cnt = 0;
        uint32_t num = n;
        while(num != 0){
            int temp = num % 2;
            ans <<= 1;
            ans += temp;
            num >>= 1;
            cnt++;
        }
        int k = 32-cnt;
        while(k--){
            ans <<= 1;
        }
        
        
        return ans;
    }
};