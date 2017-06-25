class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n, 0);
        int cur = 1;
        for(int i = 0; i < n; ++i){
            v[i] = cur;
            if(cur*10 <= n){
                cur *= 10;
            }
            else{
                if(cur >= n)
                    cur /= 10;
                cur += 1;
                while(cur % 10 == 0)
                    cur /= 10;
            }
            
        }
        return v;
    }
};