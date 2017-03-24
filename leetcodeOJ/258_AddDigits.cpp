//方法一
class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(1){
            if(!(num/10)){
                return num;
            }
            int sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            num = sum;
            
        }
        //return ans;
    }
};




//方法二：
class Solution {
public:
    int addDigits(int num) {
        //int ans = 0;
        ///<If an integer is like 100a+10b+c, then (100a+10b+c)%9=(a+99a+b+9b+c)%9=(a+b+c)%9
        if(!num)
            return 0;
        if(num%9 == 0)
            return 9;
        else
            return num%9;
    }
};