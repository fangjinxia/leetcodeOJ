class Solution {
public:
    int findNthDigit(int n) {
        long long base = 9;
        int k = 1;
        while(n > base*k){
            n -= base*k;
            k++;
            base *= 10;
        }
        
        base = 1;
        for(int i = 1; i < k; i++){
            base *= 10;
        }
        int idx = n % k;
        int num = base + ((idx == 0) ? (n/k - 1) : n/k);
        cout << base << ' ' << num << endl;
        
        vector<int> v(k, 0);
        for(int i = k-1; i >= 0; i--){
            v[i] = num%10;
            num /= 10;
                
        }
        
        return (idx==0) ? v[k-1] : v[idx-1];
    }
};