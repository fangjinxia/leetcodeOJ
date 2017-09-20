class Solution {
public:
    bool checkValidString(string s) {
        stack<int> c1, c2;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                c1.push(i);
            }
            else if(s[i] == '*'){
                c2.push(i);
            }
            else{
                if(!c1.empty()){
                    c1.pop();
                }
                else{
                    if(!c2.empty())
                        c2.pop();
                    else 
                        return false;
                }
            }
        }
        
        while(!c1.empty() && !c2.empty()){
            if(c1.top() < c2.top()){
                c1.pop();
                c2.pop();
            }
            else
                return false;
        }
        return c1.empty();
        
    }
};