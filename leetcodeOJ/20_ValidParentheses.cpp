class Solution {
public:
    bool isValid(string s) {
        vector<char> str;
        for(int i = 0; i < s.size(); i++){
           if(s[i] == '(' || s[i] == '{' || s[i] == '['){
               str.push_back(s[i]);
               continue;
           }
           else if(s[i] == ')'){
               if(str.empty() || str.back() != '(')
                   return false;
               else{
                   str.pop_back();
                   continue;
               }
           }
           else if(s[i] == '}'){
               if(str.empty() || str.back() != '{')
                   return false;
               else{
                   str.pop_back();
                   continue;
               }
           }
           else if(s[i] == ']'){
               if(str.empty() || str.back() != '[')
                   return false;
               else{
                   str.pop_back();
                   continue;
               }
           }
           else
               continue;
        }
        
        return str.empty();
    }
};