class Solution {
public:
    int romanToInt(string s) {
        ///<��һ����������תΪ����
        unordered_map<char, int> Table = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
         };
         ///<��s���ұ�������ƣ�
         int len = s.size();
         int sum = Table[s[len-1]];
         for(int i = len-2; i >= 0; i--){
             if(Table[s[i]] < Table[s[i+1]]){
                 sum -= Table[s[i]];
             }
             else{
                 sum += Table[s[i]];
             }
         }

         return sum;
    }
};
