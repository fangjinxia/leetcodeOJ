class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1)
            return 1;
        vector<int> ans(0);
        ans.push_back(1);
        vector<int> idx(primes.size(), 0);
        while(ans.size() < n){
            int tmp = INT_MAX;
            for(int i = 0; i < primes.size(); i++){
                tmp = min(tmp, primes[i]*ans[idx[i]]);
            }
            ans.push_back(tmp);
            for(int i = 0; i < primes.size(); i++){
                if(tmp == primes[i]*ans[idx[i]])
                    idx[i]++;
            }
        }
        return ans.back();
    }
};