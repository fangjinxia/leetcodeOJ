//����3�������ϵ�L��2�������ϵ�A���򷵻�false
class Solution {
public:
    bool checkRecord(string s) {
        int numOfA = 0;
        if(s.length() < 2)
            return true;
        int i = 0;
        while(i < 2){
            if(s[i] == 'A'){
                numOfA++;
            }
            i++;
        }
        for(; i < s.length(); i++){
            if(numOfA >= 2 || s.substr(i-2, 3) == "LLL")
                return false;
            else if(s[i] == 'A')
                numOfA++;
        }
        return (numOfA > 1) ? false : true;
    }
};