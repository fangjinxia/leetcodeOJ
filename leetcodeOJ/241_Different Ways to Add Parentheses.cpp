class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i = 0; i < input.length(); i++){
            char cur = input[i];
            if(cur == '+' || cur == '-' || cur == '*'){
                vector<int> re1 = diffWaysToCompute(input.substr(0, i));
                vector<int> re2 = diffWaysToCompute(input.substr(i+1));
                for(auto r1 : re1){
                    for(auto r2 : re2){
                        if(cur == '+')
                            ans.push_back(r1+r2);
                        else if(cur == '-')
                            ans.push_back(r1-r2);
                        else
                            ans.push_back(r1*r2);
                    }
                }
            }
        }
        
        if(ans.size()==0)
            ans.push_back(atoi(input.c_str())); 
        return ans;
    }
};