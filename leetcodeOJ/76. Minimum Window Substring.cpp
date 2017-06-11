class Solution {
public:
    string minWindow(string s, string t) {
        int min_len = INT_MAX;
        string res = "";
        vector<int> v(128, 0);
        for(int i = 0; i < t.length(); ++i){
            ++v[t[i]];
        }
        
        int left = 0, right = 0;
        vector<int> tmp(128, 0);
        int n = s.length();
        while(right < n){
            do{
                ++tmp[s[right++]];
            }while(right < n && !isSubString(v, tmp));
            while(left < right && isSubString(v, tmp)){
                --tmp[s[left]];
                ++left;
            }
            --left;
            ++tmp[s[left]];
            if(isSubString(v, tmp)){
                if(min_len > right-left){
                    min_len = right-left;
                    //cout << min_len << endl;
                    res = s.substr(left, right-left);
                }
                
            }
                
        }
        return res;
    }
    
    bool isSubString(vector<int>& v, vector<int>& tmp){
        for(int i = 0; i < v.size(); i++){
            if(v[i] > tmp[i])
                return false;
        }
        return true;
    }
};