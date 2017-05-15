class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> v(0);
        v.push_back(1);//nÎª0Ê±£¬·µ»Ø1
        int cur = 1;
        for(int i = 1; i <= 10; i++){
            int tmp = 9, k = 9;
            for(int j = i-1; j > 0; j--){
                tmp *= k;
                k--;
            }
            cur += tmp;
            v.push_back(cur);
        }
        return (n > 10) ? v[10] : v[n];
    }
};