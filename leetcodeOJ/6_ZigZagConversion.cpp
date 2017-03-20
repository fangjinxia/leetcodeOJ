class Solution {
public:
    string convert(string s, int numRows) {
        int aux = 2*(numRows - 1);
        int len = s.size();
        string ans = "";
        
        if(aux == 0)
            return s;
        int m = (len+aux-1)/aux;
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0){
                    if(aux*j < len)
                        ans += s[aux*j];
                }   
                else if(i == numRows-1){
                    if(aux*j + i < len)
                        ans += s[aux*j + i];
                }
                else{
                    if(j == 0){
                        if(i < len)
                            ans += s[i];
                    }
                    else{
                        if(aux*j-i < len)
                            ans += s[aux*j-i];
                        if(aux*j+i < len)
                            ans += s[aux*j+i];
                    }
                }
            }
        }
        
        return ans;
    }
};