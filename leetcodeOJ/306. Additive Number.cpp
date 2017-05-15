class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; i++){
            for(int j = 1; j <= (num.size()-i)/2; j++){
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }
    
    bool check(string num1, string num2, string str){
        if((num1.length() > 1 && num1[0] == '0') || (num2.length() > 1 && num2[0] == '0'))
            return false;
        
        string s = add(num1, num2);
        //cout << num1 << ' ' << num2 << ' ' << s << endl;
        if(s == str)
            return true;
        if(str.length() < s.length())
            return false;
        if(s != str.substr(0, s.length()))
            return false;
        
        return check(num2, s, str.substr(s.length()));
        
    }
    
    string add(string num1, string num2){
        string s = "";
        int c = 0;
        for(int i = num1.length()-1, j = num2.length()-1; i >= 0 || j >= 0; i--, j--){
            int tmp1 = (i>=0) ? (num1[i]-'0') : 0;
            int tmp2 = (j>=0) ? (num2[j]-'0') : 0;
            s += to_string((tmp1+tmp2+c)%10);
            c = (tmp1+tmp2+c)/10;
        }
        
        if(c != 0)
            s += to_string(c);
        reverse(s.begin(), s.end());
        //cout <<s << endl;
        return s;
    }
};