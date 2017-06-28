class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo = 0, hi = 0;
        vector<int> v(26, 0);
        int res = 0;
        while(hi < s.length()){
            ++v[s[hi]-'A'];
            ++hi;
            if(hi - lo - *max_element(v.begin(), v.end()) > k){
                --v[s[lo]-'A'];
                ++lo;
            }
            
            res = max(res, hi-lo);
        }
        
        return res;
    }
};