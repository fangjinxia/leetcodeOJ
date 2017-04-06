class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxThreePowerInt = 1162261467;
        if(n <= 0 || n > maxThreePowerInt)
            return false;
        return !(maxThreePowerInt % n);
        
    }
};


或者下面这种解法
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        return !fmod(log10(n)/log10(3), 1);
        
    }
};

