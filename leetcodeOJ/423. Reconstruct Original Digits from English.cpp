class Solution {
public:
    string originalDigits(string s) {
        //zero one two three four five six seven eight nine 
        vector<int> v(26, 0);
        for(int i = 0; i < s.length(); i++){
            v[s[i]-'a']++;
        }
        vector<int> n(10, 0);
        n[0] = v['z'-'a'];
        n[2] = v['w'-'a'];
        n[4] = v['u'-'a'];
        n[6] = v['x'-'a'];
        n[7] = v['s'-'a'] - n[6];
        n[8] = v['g'-'a']; 
        n[3] = v['h'-'a'] - n[8];
        n[1] = v['o'-'a'] - n[0] - n[2] - n[4];
        n[5] = v['v'-'a'] - n[7];
        n[9] = v['i'-'a'] - n[5] - n[6] - n[8];
        
        string ss = "";
        for(int i = 0; i <= 9; i++){
            while(n[i] != 0){
                ss += to_string(i);
                n[i]--;
            }
        }
        
        return ss;
    }
};