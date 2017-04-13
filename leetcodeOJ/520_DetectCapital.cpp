class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int flag = 0;
        if(isupper(word[0]))
            flag = 1;
        if(flag == 0){
            for(int i = 1; i < n; i++)
                if(isupper(word[i]))
                    return false;
        }
        else{
            for(int i = 1; i < n; i++){
                if(i == 1){
                    if(isupper(word[i]))
                        flag = 2;
                }
                else{
                    if(flag == 1){
                        if(isupper(word[i]))
                            return false;
                    }
                    else{
                        if(!isupper(word[i]))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};