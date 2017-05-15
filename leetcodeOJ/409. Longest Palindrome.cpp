class Solution {
public:
    int longestPalindrome(string s) {
        //cout<<'z'-'A'<<endl;
        vector<int> v(58, 0);
        for(int i = 0; i < s.length(); i++){
            v[s[i]-'A']++;
        }
        
        int ans = 0;
        bool mark = false;
        for(int i = 0; i < v.size(); i++){
            if(v[i]%2 == 0)
                ans += v[i];
            else{
                mark = true;
                ans += (v[i]-1);
            }
        }
        
        return (mark) ? ans+1 : ans;
    }
};