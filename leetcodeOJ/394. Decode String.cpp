class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s,i);
    }
    
    string helper(string s, int& i){
        string res = "";
        
        while(i < s.length() && s[i] != ']'){
            if(!isdigit(s[i]))
                res += s[i++];
            else{
                int tmp = 0;
                while(i < s.length() && isdigit(s[i]))
                    tmp = tmp*10 + s[i++]-'0';
                    
                i++;//'['
                string t = helper(s, i);
                i++;//']'
                
                while(tmp--){
                    res += t;
                }
            }
                
                
        }
        
        return res;
    }
    
};