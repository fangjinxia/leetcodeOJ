class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0;
        int hi = sqrt(c);
        while(lo <= hi){
            int num = lo*lo + hi*hi;
            if(num == c)
                return true;
            if(num < c)
                ++lo;
            else
                --hi;
        }
        return false;
    }
};