class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(), '0');
        
        for(int i = num1.size()-1; i >= 0; i--){
            int c = 0; //½øÎ»
            for(int j = num2.size()-1; j >= 0; j--){
                int temp = (ans[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + c;
                ans[i+j+1] = temp % 10 + '0';
                c = temp / 10;
            }
            ans[i] += c;
        }
        int where = ans.find_first_not_of('0');
        if(string::npos == where){
            return "0";
        }
        return ans.substr(where);
    }
};