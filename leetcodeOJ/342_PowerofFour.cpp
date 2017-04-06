class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        return !fmod(log10(num)/log10(4), 1);
    }
};