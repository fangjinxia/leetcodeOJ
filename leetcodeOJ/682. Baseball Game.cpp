class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack<int> st;
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == "C"){
                sum -= st.top();
                st.pop();
            }
            else if(ops[i] == "D"){
                int tmp = st.top();
                tmp *= 2;
                st.push(tmp);
                sum += tmp;
            }
            else if(ops[i] == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                int tmp = num1 + num2;
                st.push(num1);
                st.push(tmp);
                sum += tmp;
            }
            ///<Êý×Ö
            else{
                int tmp = atoi(ops[i].c_str());
                st.push(tmp);
                sum += tmp;
            }
        }
        
        return sum;
    }
};