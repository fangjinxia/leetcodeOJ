class Solution {
public:
   double myPow(double x, int n) {
        //注意n可能为负数
        int flag = true;
        long num = (long)n;
        if(num < 0){
            flag = false;
            num = -num;
        }
        
        double ans = 1.0;
        while(num > 0){
            if((num&1) == 1){
                ans *= x;
            }
            num = num >> 1;
            x *= x;
        }
        
        ans = (flag) ? ans : 1/ans;
        return ans;
    }
};