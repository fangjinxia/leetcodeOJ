class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> p;
        string str = "";
        for(int i = 0; i < preorder.length(); i++){
            if(preorder[i] != ',')
                str += preorder[i];
            else{
                p.push_back(str);
                str = "";
            }
        }
        p.push_back(str);
        
        int slot = 1;
        for(int i = 0; i < p.size(); i++){
            if(slot <= 0)
                return false;
            if(p[i] == "#")
                slot -= 1;
            else
                slot += 1;
        }
        return slot==0;
    }
};