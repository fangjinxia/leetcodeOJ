class Solution {
public:
    string intToRoman(int num) {
        ///<��һ������תΪ��������
         int numArr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
         string strArr[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

         string ans = "";
         for(int i = 0; i < 13; i++){
             while(num >= numArr[i]){
                 ans += strArr[i];
                 num -= numArr[i];
             }
         }

         return ans;
    }
};
