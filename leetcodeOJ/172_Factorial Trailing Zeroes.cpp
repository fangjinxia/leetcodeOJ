class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        for(long long m = 5; m <= n; m *= 5){
            zeros += n/m;
        }
        return zeros;
    }
};