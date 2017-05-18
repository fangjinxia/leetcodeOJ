class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        if(num == 1)
            return false;
        int m = sqrt(num);
        // cout << m << endl;
        for(int i = 2; i <= m; i++){
            if(i == m && m*m == num){
                sum += m;
                break;
            }
            else if(num % i == 0){
                sum += i;
                sum += (num/i);
            }
        }
        return num == sum;
    }
};