/*
n == 1

Only 2 possibilities: 1 and 0.

n == 2

After one operation, it has only 4 possibilities: 11, 10 and 01.
After two and more operations, it has only 4 possibilities: 11, 10, 01 and 00.

n == 3

After one operation, it has only 4 possibilities: 111, 101, 010 and 011.
After two operations, it has 7 possibilities: 111,101,010,011,000,001 and 110.
After three and more operations, it has 8 possibilities, plus 100 on above case.

n >= 4

After one operation, it has only 4 possibilities: 1111, 1010, 0101 and 0110.
After two or more operations: it has 8 possibilities, 1111,1010,0101,0111,0000,0011, 1100 and 1001.
*/

class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1? 3:4;
        if (m == 1) return 4;
        return m == 2? 7:8;
        
    }
};