class Solution {
public:
    int idx1 = 0, idx2 = 0;
    int maximumSwap(int num) {
        if(num < 1)
            return 0;
        string s = to_string(num);
        get_max(s, 0);///<从第0位开始
        char c = s[idx1];
        s[idx1] = s[idx2];
        s[idx2] = c;
        return atoi(s.c_str());
    }
    
    void get_max(string s, int k) {
        if(k >= s.length()-1)
            return ;
        int tmp = k;
        for(int i = k+1; i < s.length(); ++i){
            if(s[i] >= s[k])
                k = i;
        }
        if(tmp != k && s[tmp] < s[k]){
            ///<swap
            idx1 = tmp; 
            idx2 = k;
            return ;
        }
        else{
            // while(k < s.length() && (s[k] == s[k+1])){
            //     ++k;
            // }
            get_max(s, tmp+1);
        }
        
        return ;
    }
};