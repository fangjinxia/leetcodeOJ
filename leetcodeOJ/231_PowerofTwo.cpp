//思路：power of two 表示n的bit位上只有一位为1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return !(n&(n-1));
    }
};