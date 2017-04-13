//想到种方法，可以把string按'/'分割，然后利用栈再讨论是push还是pop当前子串
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> re;
        string s = "";
        for(int i = 0; i < path.length(); i++){
            if(s == ".." && path[i] == '/'){
                if(re.size() != 0)
                    re.pop_back();
                s.clear();
            }
            else if(path[i] != '/'){
                s += path[i];
            }
            else if(s.length() != 0){
                if(s != "."){
                    re.push_back(s);
                }
                s.clear();
            }
            else
                continue;
        }
        if(s == ".."){
            if(re.size() != 0)
                re.pop_back();
        }
        else if(s.length() != 0 && s != "."){
            re.push_back(s);
        }
        string ans = "";
        for(int i = 0; i < re.size(); i++){
            ans += "/";
            ans += re[i];
        }
        return (ans.length() == 0) ? "/" : ans;
    }

};