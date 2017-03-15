class Solution {
public:
    int reverse(int x) {
        int flag = 0;//判断x是否为负，flag为0时默认为正数
        if(abs(x) != x){
            flag = 1;
            x = abs(x);
        }

        long long ans = 0;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        if(ans < INT_MIN || ans > INT_MAX){
            return 0;
        }
        return (flag == 0)? ans : (0-ans);
    }
};
