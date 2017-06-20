class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        string op = "+-*/";
        //int res = 0;
        for(int i = 0; i < tokens.size(); ++i){
            if(op.find(tokens[i]) != string::npos){//是op里的其中一个
                int tmp1 = s.top();
                s.pop();
                int tmp2 = s.top();
                s.pop();
                if(tokens[i] == "+"){
                    s.push(tmp1+tmp2);
                }
                else if(tokens[i] == "-"){
                    s.push(tmp2-tmp1);
                }
                else if(tokens[i] == "*"){
                    s.push(tmp1*tmp2);
                }
                else if(tokens[i] == "/"){
                    s.push(tmp2/tmp1);
                }
            }
            else{//是数字
                int tmp = 0;
                stringstream ss;
                ss << tokens[i];
                ss >> tmp;
                s.push(tmp);
            }
        }
        return s.top();
    }
};