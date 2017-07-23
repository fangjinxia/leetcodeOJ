class Solution {
public:
    int longestSubstring(string s, int k) {        
        return findAns(s, k, 0, s.length());
    }
    
    int findAns(string s, int k, int first, int last){
        vector<int> cnt(26, 0);
        for(int i = first; i < last; ++i){
            ++cnt[s[i]-'a'];
        }
        
        int res = 0;
        for(int i = first; i < last; ++i){
            while(i < last && (cnt[s[i]-'a'] < k))
                ++i;
            if(i == last)
                break;
            int j = i;
            while(j < last && (cnt[s[j]-'a'] >= k))
                ++j;
            if(i == first && j == last)
                return last-first;
            
            res = max(res, findAns(s, k, i, j));
            i = j;
        }
        
        return res;
        
    }
};