class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size();
        string ans = "";
        int i = 0;
        int left_count = 0, right_count = 0;
        int left_val = 0, right_val = 0;
        bool isLeft = true;
        while(i < n){
            if(isdigit(equation[i])){
                int num = equation[i] - '0';
                int sign = (i > 0 && equation[i-1] == '-') ? -1 : 1;
                while(i < n-1 && isdigit(equation[i+1])){
                    i++;
                    num = num * 10 + equation[i] - '0';                    
                }                     
                num *= sign;
                if(i < n-1 && equation[i+1] == 'x'){
                    if(isLeft) left_count += num;
                    else right_count += num;
                }else{
                    if(isLeft) left_val += num;
                    else right_val += num;
                }
            }else if(equation[i] == '='){
                isLeft = false;
            }else if(equation[i] == 'x' && (i == 0 || !isdigit(equation[i-1]))){
                int sign = (i > 0 && equation[i-1] == '-') ? -1 : 1;
                if(isLeft) left_count += sign;
                else right_count += sign;
            }    
            i++;
        }
        if(left_count == right_count){
            if(left_val == right_val) return "Infinite solutions";
            else return "No solution";
        }
        int coeff = left_count - right_count;
        int val = right_val - left_val;
        if(val == 0){
            return "x=0";
        }
        else{
            int tmp = int(val) / coeff;
            ans = "x=" + to_string(tmp);
        }
        return ans;
    
    }
};