/*
One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
*/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0){
            return 1;
        }
        int lastNum = b.back();
        b.pop_back();
        return pow(superPow(a, b), 10) * pow(a, lastNum) % 1337;
    }
    
private:
    int pow(int a, int last){
        a %= 1337;
        int ans = 1;
        for(int i = 0; i < last; i++){
            ans *= a;
            ans %= 1337;
        }
        return ans;
    }
};