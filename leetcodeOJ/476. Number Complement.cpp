class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
            
        long long n = 1;
        for(; ; n *= 2){
            if((num >= n/2) && (num < n)){
                break;
            }
        }
        return n-1-num;
    }
};