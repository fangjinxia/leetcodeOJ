class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //And��������ĳһλ�ϱ������еĶ���1�������������Ϊ1
        return (n > m) ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
    }
};