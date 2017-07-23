class Solution {
public:
    //hashmap
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.size() == 0)
            return sentence;
    
        set<string> set(dict.begin(), dict.end());
        string ans = "";
        vector<string> words(0);
        string c = " ";
        splitString(sentence, words, c);
        
        for(int i = 0; i < words.size(); ++i){
            string ss = "";
            for(int len = 1; len <= words[i].length(); ++len){
                ss = words[i].substr(0, len);
                if(set.find(ss) != set.end())
                    break;
            }
            
            ans += ss;
            ans += (i == words.size()-1) ? "" : " ";
        }
        
        return ans;
    }
    
    void splitString(string sentence, vector<string>& words, string c){
        string::size_type pos1, pos2;
        pos2 = sentence.find(c);
        pos1 = 0;
        while(string::npos != pos2)
        {
            words.push_back(sentence.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = sentence.find(c, pos1);
        }
        if(pos1 != sentence.length())
            words.push_back(sentence.substr(pos1));
    }
};