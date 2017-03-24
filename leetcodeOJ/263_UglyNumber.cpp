class Solution {
public:
    bool isUgly(int num) {
        if(num < 1)
            return false;
        if(num == 1)
            return true;
        
        int div[3] = {2, 3, 5};
        for(int i = 0; i < 3; i++){
            int cur = num / div[i];
            while(num == div[i]*cur){
                num = cur;
                cur = num / div[i];
            }
            if(num == 1)
                return true;
        }
        return false;
    }
};