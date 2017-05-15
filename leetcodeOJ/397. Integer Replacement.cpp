class Solution {
public:
    int integerReplacement(int n) {
        return genAns((long long)n, 0);
    }
    
    int genAns(long long n, int k){
        if(n == 1)
            return k;
        if(n % 2 == 0)
            return genAns(n>>1, k+1);
        else if(n % 2 == 1){
            int ans1 = genAns(n+1, k+1);
            int ans2 = genAns(n-1, k+1);
            return min(ans1, ans2);
        }
    }
};