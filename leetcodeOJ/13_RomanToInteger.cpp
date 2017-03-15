class Solution {
public:
    int romanToInt(string s) {
        ///<把一个罗马数字转为整型
        unordered_map<char, int> Table = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
         };
         ///<从s的右边往左边推，
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
