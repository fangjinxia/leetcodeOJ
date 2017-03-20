class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> Table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        ans.push_back("");
        for(int i = 0; i < digits.size(); i++){
            int digit = digits[i]-'0';
            if(digit == 1){
                vector<string> r;
               // r.push_back("");
                return r;
            }
            if(Table[digit] == ""){
                continue;
            }
            
            vector<string> temp;
            for(int j = 0; j < Table[digit].size(); j++){
                for(int k = 0; k < ans.size(); k++){
                    temp.push_back(ans[k]+Table[digit][j]);
                }
            }
            
            ans.swap(temp);
        }
        
        return ans;
    }
};