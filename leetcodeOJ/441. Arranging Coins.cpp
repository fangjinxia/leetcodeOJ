class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 1;
        long long cur = 0;
        for(; ; i++){
            long long tmp = i*(i+1)/2;
            if(n >= cur && n < tmp){
                return i-1;
            }
            cur = tmp;
        }
    }
};