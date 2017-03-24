class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //自己没想出来，借鉴下别人的思路
        //计算每个num在每个bit位上的为1的个数和，
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int n = 0;
            for(int j = 0; j < nums.size(); j++){
                if(((nums[j] >> i) & 1) == 1)
                    n++;
            }
            n %= 3;
            
            if(n)
                ans += (n << i);
        }
        
        return ans;
    }
};