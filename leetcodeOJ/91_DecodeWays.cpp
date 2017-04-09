//思路：动态规划
/*递推式：
 *1.00: ans[i] = 0
 *2.11-19、21-26: ans[i] = ans[i-1]+ans[i-2]
 *3.10、20：ans[i] = ans[i-2]
 *4.01-09、27-99: ans[i] = ans[i-1]
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0')
            return 0;
        
        int n1 = 1; 
        int n2 = 1;
        int n3 = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2')
                    n3 = n1;
                else
                    return 0;
            }   
            else if((s[i-1] >= '3') || (s[i-1] == '0') || (s[i-1] == '2' && s[i] >= '7' && s[i] <= '9')){
                n3 = n2;
            }
            else{
                n3 = n1 + n2;
            }
            n1 = n2;
            n2 = n3;
        }
        
        return n2;
    }
};