class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0){
            digits.push_back(1);
            return digits;
        }
        
        if(digits[n-1] != 9){//最末尾不是9
            digits[n-1] += 1;
            return digits;
        }
        else{
            int c = 1;//进位
            digits[n-1] = 0;
            for(int i = n-2; i >= 0; i--){
                if(c == 0)
                    break;
                int temp = digits[i] + c;
                digits[i] = temp % 10;
                c = temp / 10;
            }
            if(c == 1)
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};