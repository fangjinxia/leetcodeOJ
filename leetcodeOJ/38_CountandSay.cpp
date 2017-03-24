class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n == 1)
            return ans;
        while(--n){
            string str = "";
            for(int i = 0; i < ans.size();i++){
                int num = 1;
                while(i < ans.size()-1 && ans[i] == ans[i+1]){
                    i++;
                    num++;
                }
                str += to_string(num) + ans[i];
            }
            ans = str;
        }
        return ans;
    }
};