class Solution {
public:
    bool canWinNim(int n) {
        //如果n是4的倍数，那么就不可能赢，否则，就会赢
        return n%4;
    }
};