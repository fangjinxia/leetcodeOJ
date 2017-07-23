class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int tmp = 0;
        char sign = '+';
        for(int i = 0; i < s.length(); ++i){
            if(isdigit(s[i]))
                tmp = 10*tmp + s[i] - '0';
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1){
                if(sign == '-')
                    st.push(-tmp);
                else if(sign == '+')
                    st.push(tmp);
                else {
                    int num;
                    if(sign == '*')
                        num = st.top() * tmp;
                    else
                        num = st.top() / tmp;
                    
                    st.pop();
                    st.push(num);
                }
                
                tmp = 0;
                sign = s[i];
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};