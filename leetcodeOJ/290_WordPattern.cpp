class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //处理str
        vector<string> dealedStr;
        for(int i = 0; i < str.size(); i++){
            string s = "";
            if(str[i] == ' ')
                continue;
            while(str[i] != ' ' && i < str.size()){
                s += str[i];
                i++;
            }
            dealedStr.push_back(s);
        }
        if(pattern.size() != dealedStr.size())
            return false;
        int i = 0;
        for(i = 1; i < pattern.size(); i++){
            int it = 0;
            while(pattern[it] != pattern[i] && it < i){
                it++;
            }
            cout<<it<<endl;
            if(it != i){//如果能找到
                if(dealedStr[i] != dealedStr[it])
                    return false;
            }
            else{//如果找不到，需要保证与其他匹配的字符串不一样
                for(int j = 0; j < i; j++){
                    if(dealedStr[j] == dealedStr[i])
                        return false;
                }
            }
        }
        
        if(i == pattern.size())
            return true;
    }
};