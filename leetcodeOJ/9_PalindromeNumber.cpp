class Solution {
public:
    bool isPalindrome(int x) {
        ///<判断数字是不是回文串,without extra space
        if(x < 0)
            return false;
        int num = x;
        long long ans = 0;
        while(num){
            ans = ans * 10 + num % 10;
            num /= 10;
        }

        if(ans > INT_MAX || ans < INT_MIN){
            return false;
        }
        return (x == ans)? true: false;
    }
};
