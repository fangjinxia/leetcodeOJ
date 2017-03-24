class Solution {
public:
    int sumOfSquare(int num){
        int ans = 0;
        while(num){
            ans += (num%10)*(num%10);
            num /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        int pre, cur;
        pre = n;
        cur = n;
        do{
            pre = sumOfSquare(pre);
            cur = sumOfSquare(cur);
            cur = sumOfSquare(cur);
        }while(cur != pre);
        
        if(cur == 1)
            return true;
        else
            return false;
        
    }
};