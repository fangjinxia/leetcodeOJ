class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        for(; str[i] == ' '; i++)
            ;
            
        int flag = 1;///<flag=1表示为正数
        if(str[i] == '+'){
            i++;
            
        }
        else if(str[i] == '-'){
            flag = -1;
            i++;
        }
        
        long long res = 0;
        for(; i < str.size(); i++){
            if(str[i] < '0' || str[i] > '9')
                break;
            else{
                res = res*10 + str[i] - '0';
            }
            long long aux = flag * res;
            if(aux >= INT_MAX)
                return INT_MAX;
            else if(aux <= INT_MIN)
                return INT_MIN;
        }
        cout << flag << endl;
        
        int ans = flag * (int)res;
        
        return ans;
    }
};