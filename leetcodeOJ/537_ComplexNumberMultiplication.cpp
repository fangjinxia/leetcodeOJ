class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        //处理字符串a
        int k = a.find('+', 0);
        string temp = a.substr(0, k);
        int a1 = atoi(temp.c_str());
        temp = a.substr(k+1, a.size()-k-2);
        int a2 = atoi(temp.c_str());
        
        //处理字符串b
        k = b.find('+', 0);
        temp = b.substr(0, k);
        int b1 = atoi(temp.c_str());
        temp = b.substr(k+1, b.size()-k-2);
        int b2 = atoi(temp.c_str());
        
        int c1 = a1*b1 - a2*b2;
        int c2 = a1*b2 + a2*b1;
        string ans = to_string(c1) + '+' + to_string(c2) + 'i';
        
        return ans;
    }
};