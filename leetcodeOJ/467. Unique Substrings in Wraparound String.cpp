class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.length();
        
        vector<int> v(26, 0);
        int curLen = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0 && ((p[i] == p[i-1]+1) || (p[i-1]-p[i] == 25))){
                ++curLen;
            }
            else
                curLen = 1;
            
            int tmp = p[i]-'a';
            v[tmp] = max(v[tmp], curLen);
        }
        
        int ans = accumulate(v.begin(), v.end(), 0);
        
        return ans;
    }
}; 