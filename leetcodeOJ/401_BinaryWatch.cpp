class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(bitset<10>(i<<6 | j).count() == num){
                    string s = to_string(i) + ((j < 10) ? ":0" : ":") + to_string(j);
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};