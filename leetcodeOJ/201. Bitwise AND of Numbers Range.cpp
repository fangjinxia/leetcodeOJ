class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //And操作，在某一位上必须所有的都是1，操作后的数才为1
        return (n > m) ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
    }
};