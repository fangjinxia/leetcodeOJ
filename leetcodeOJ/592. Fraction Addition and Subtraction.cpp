class Solution {
public:
    string fractionAddition(string expression) {
        string op = "+-";
        int a1 = 0;
        int b1 = 1;
        int f1 = 0;
        int f2 = (expression[0] == '-') ? 1 : 0;//f1为1,则为负数
        int i = (f2 == 1) ? 1 : 0;
        bool flag = true;
        while(i < expression.length()){
            int idx = expression.find_first_of(op, i);
            if(idx == string::npos){
                flag = false;
            }
            string s = "";
            if(flag)
                s = expression.substr(i, idx-i);
            else
                s = expression.substr(i);
                
            int a2 = 0, b2 = 0;
            //求a2,b2
            int j = 0;
            for(; j < s.length() && s[j] !='/'; ++j){
                a2 *= 10;
                a2 += s[j]-'0';
            }
            if(j == s.length())
                b2 = 1;
            else{
                for(++j; j < s.length(); ++j){
                    b2 *= 10;
                    b2 += s[j]-'0';
                }
            }
            //计算a1/b1 a2/b2的值
            if(f2 == 1)
                a2 = 0-a2;
            a1 = a1*b2 + a2*b1;
            b1 *= b2;
            
            //为下一轮做准备
            if(!flag)
                break;
            f2 = (expression[idx] == '-') ? 1 : 0;
            i = idx+1;
        }
        //计算最后的分数
        //cout << a1 <<' ' << b1<< endl;
        string res = "";
        if(a1 == 0)
            return "0/1";
        else if(a1 < 0){
            res += '-';
            a1 = abs(a1);
        }
            
        if(b1 != 0){
            int num = gcd(a1, b1);
            a1 /= num;
            b1 /= num;
            res += to_string(a1) + "/" + to_string(b1);
        }
        else{
            res += "1/0";
        }
        return res;
    }
    
    int gcd(int a, int b){
        int max = (a > b) ? a : b;
        int min = (a < b) ? a : b;
        if(max % min == 0)  
            return min;
        else
            return gcd(min, max%min);
    }
};