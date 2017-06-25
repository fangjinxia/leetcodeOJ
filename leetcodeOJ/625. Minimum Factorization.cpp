class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 2)
            return a;
        long long res = 0;
        for(int i = 9, d = 0; i >= 2 && d < 10; --i){
            while(a % i == 0 && d < 10){
                res += i * pow(10, d++);
                a /= i;
            }
        }
        
        return (a > 1 || (res > INT_MAX)) ? 0 : res;
    }
};