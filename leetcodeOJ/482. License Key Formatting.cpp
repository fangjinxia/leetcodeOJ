class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        reverse(S.begin(), S.end());
        string res = "";
        int k = K;
        for(int i = 0; i < S.length(); ++i){
            if(S[i] == '-')
                continue;
            
            res += (S[i] >= 'a' && S[i] <= 'z') ? S[i]+'A'-'a': S[i];
            --k;
            if(k == 0 && i != S.length()-1){
                k = K;
                res += "-";
            }
        }
        if(res[res.length()-1] == '-')
            res = res.substr(0, res.length()-1);
        reverse(res.begin(), res.end());
        return res;
    }
};