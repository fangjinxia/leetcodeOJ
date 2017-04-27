class Solution {
public:
    string getHint(string secret, string guess) {
        int numB = 0;
        int numC = 0;
        
        int m = secret.length(), n = guess.length();
        for(int i = 0; i < min(m, n); i++){ //计算出bulls的个数
            if(secret[i] == guess[i])
                numB++;
        }
        
        //计算出cows的个数
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        int sum = 0;//sum表示所有既存在与secret中又存在于guess中的数字
        for(int i = 0, j = 0; i < m && j < n; ){
            if(secret[i] == guess[j]){
                i++;
                j++;
                sum++;
            }
            else if(secret[i] > guess[j])
                j++;
            else
                i++;
        }
        numC = sum - numB;
        
        string str = to_string(numB) + 'A' + to_string(numC) + 'B';
        return str;
    }
};