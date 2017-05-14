class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 1;
        long long hi = num;
        while(lo < hi){
            long long mid = lo+(hi-lo)/2;
            long long n = mid*mid;
           //cout << mid << ' ' << n<<endl;
            if(n == num)
                return true;
            if(n < num)
                lo = mid+1;
            else
                hi = mid-1;
        }
        if(lo * lo == num) 
            return true;
        return false;
    }
};